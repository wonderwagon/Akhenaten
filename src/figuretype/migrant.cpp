#include "migrant.h"

#include "building/house.h"
#include "building/model.h"
#include "city/map.h"
#include "city/population.h"
#include "city/city_data.h"
#include "core/calc.h"
#include "core/random.h"
#include "core/profiler.h"
#include "figure/combat.h"
#include "figure/image.h"
#include "figure/movement.h"
#include "figure/route.h"
#include "graphics/image.h"
#include "graphics/image_groups.h"
#include "grid/road_access.h"
#include "grid/terrain.h"

void figure_create_immigrant(building* house, int num_people) {
    map_point& entry = city_map_entry_point();
    figure* f = figure_create(FIGURE_IMMIGRANT, entry, DIR_0_TOP_RIGHT);
    f->action_state = FIGURE_ACTION_1_IMMIGRANT_CREATED;
    f->set_immigrant_home(house->id);
    house->set_figure(BUILDING_SLOT_IMMIGRANT, f->id);
    f->wait_ticks = 10 + (house->map_random_7bit & 0x7f);
    f->migrant_num_people = num_people;
}

void figure_create_emigrant(building* house, int num_people) {
    city_population_remove(num_people);
    if (num_people < house->house_population) {
        house->house_population -= num_people;
    } else {
        house->house_population = 0;
        building_house_change_to_vacant_lot(house);
    }

    figure* f = figure_create(FIGURE_EMIGRANT, house->tile, DIR_0_TOP_RIGHT);
    if (house->subtype.house_level >= HOUSE_COMMON_MANOR) {
        city_migration_nobles_leave_city(num_people);
    }

    f->action_state = FIGURE_ACTION_4_EMIGRANT_CREATED;
    f->wait_ticks = 0;
    f->migrant_num_people = num_people;
}

void figure_create_homeless(tile2i tile, int num_people) {
    figure* f = figure_create(FIGURE_HOMELESS, tile, DIR_0_TOP_RIGHT);
    f->action_state = FIGURE_ACTION_7_HOMELESS_CREATED;
    f->wait_ticks = 0;
    f->migrant_num_people = num_people;
    city_population_remove_homeless(num_people);
}

void figure::update_direction_and_image() {
    //    figure_image_update(image_id_from_group(GROUP_FIGURE_MIGRANT));
    if (action_state == FIGURE_ACTION_2_IMMIGRANT_ARRIVING || action_state == FIGURE_ACTION_6_EMIGRANT_LEAVING) {
        int dir = figure_image_direction();
        cart_image_id = image_id_from_group(GROUP_FIGURE_IMMIGRANT_CART) + dir;
        figure_image_set_cart_offset((dir + 4) % 8);
    }
}

static int closest_house_with_room(map_point tile) {
    int min_dist = 1000;
    int min_building_id = 0;
    int max_id = building_get_highest_id();
    for (int i = 1; i <= max_id; i++) {
        building* b = building_get(i);
        if (b->state == BUILDING_STATE_VALID && b->house_size && b->distance_from_entry > 0
            && b->house_population_room > 0) {
            if (!b->has_figure(2)) {
                int dist = calc_maximum_distance(tile, b->tile);
                if (dist < min_dist) {
                    min_dist = dist;
                    min_building_id = i;
                }
            }
        }
    }
    return min_building_id;
}

static void add_house_population(building* house, int num_people) {
    int max_people = model_get_house(house->subtype.house_level)->max_people;
    if (house->house_is_merged)
        max_people *= 4;

    int room = max_people - house->house_population;
    if (room < 0)
        room = 0;

    if (room < num_people)
        num_people = room;

    if (!house->house_population) {
        building_house_change_to(house, BUILDING_HOUSE_CRUDE_HUT);
    }

    house->house_population += num_people;
    house->house_population_room = max_people - house->house_population;
    city_population_add(num_people);
    house->remove_figure(2);
}

bool is_near_ferry_route(int base_offset, int radius) {
    offsets_array offsets;
    map_grid_adjacent_offsets_xy(1, 1, offsets);
    for (const auto &tile_delta: offsets) {
        if (map_terrain_is(base_offset + tile_delta, TERRAIN_FERRY_ROUTE)) {
            return true;
        }
    }

    return false;
}

void figure::immigrant_action() {
    OZZY_PROFILER_SECTION("Game/Run/Tick/Figure/Immigrant");
    building* home = immigrant_home();

    switch (action_state) {
    case FIGURE_ACTION_1_IMMIGRANT_CREATED:
    case ACTION_8_RECALCULATE:
        //            is_ghost = true;
        anim_frame = 0;
        wait_ticks--;
        if (wait_ticks <= 0) {
            advance_action(FIGURE_ACTION_2_IMMIGRANT_ARRIVING);
        }
        break;
    case FIGURE_ACTION_2_IMMIGRANT_ARRIVING:
    case FIGURE_ACTION_9_HOMELESS_ENTERING_HOUSE: // arriving
        {
            OZZY_PROFILER_SECTION("Game/Run/Tick/Figure/Immigrant/Goto Building");
            if (direction <= 8) {
                int next_tile_grid_offset = tile.grid_offset() + map_grid_direction_delta(direction);
                if (map_terrain_is(next_tile_grid_offset, TERRAIN_WATER)) {
                    bool is_ferry_route = map_terrain_is(next_tile_grid_offset, TERRAIN_FERRY_ROUTE);

                    if (!is_ferry_route) {
                        is_ferry_route = is_near_ferry_route(next_tile_grid_offset, 1);
                    }
                   
                    if (!is_ferry_route) {
                        route_remove();
                    }
                }
            }

            do_gotobuilding(home, true, TERRAIN_USAGE_ANY, FIGURE_ACTION_3_IMMIGRANT_ENTERING_HOUSE, ACTION_8_RECALCULATE);

            if (direction == DIR_FIGURE_CAN_NOT_REACH) {
                routing_try_reroute_counter++;
                if (routing_try_reroute_counter > 20) {
                    poof();
                    break;
                }
                wait_ticks = 20;
                route_remove();
                state = FIGURE_STATE_ALIVE;
                direction = calc_general_direction(tile.x(), tile.y(), destination_tile.x(), destination_tile.y());
                advance_action(ACTION_8_RECALCULATE);
                roam_wander_freely = true;
            }
        }
        break;

    case FIGURE_ACTION_3_IMMIGRANT_ENTERING_HOUSE:
    case FIGURE_ACTION_10_HOMELESS_ENTERING_HOUSE:
        if (do_enterbuilding(false, home)) {
            add_house_population(home, migrant_num_people);
        }
        //            is_ghost = in_building_wait_ticks ? 1 : 0;
        break;
    }
    {
        OZZY_PROFILER_SECTION("Game/Run/Tick/Figure/Immigrant/Update Image");
        update_direction_and_image();
    }
}

void figure::emigrant_action() {
    OZZY_PROFILER_SECTION("Game/Run/Tick/Figure/Emigrant");
    tile2i exit = city_map_exit_point();
    switch (action_state) {
    case FIGURE_ACTION_4_EMIGRANT_CREATED:
        //            is_ghost = true;
        anim_frame = 0;
        wait_ticks++;
        if (wait_ticks >= 5) {
            advance_action(FIGURE_ACTION_5_EMIGRANT_EXITING_HOUSE);
        }
        break;

    case FIGURE_ACTION_5_EMIGRANT_EXITING_HOUSE:
        do_exitbuilding(false, FIGURE_ACTION_6_EMIGRANT_LEAVING);
        //            is_ghost = in_building_wait_ticks ? 1 : 0;
        break;

    case ACTION_16_EMIGRANT_RANDOM:
        roam_wander_freely = false;
        do_goto(destination_tile, TERRAIN_USAGE_ANY, FIGURE_ACTION_6_EMIGRANT_LEAVING, FIGURE_ACTION_6_EMIGRANT_LEAVING);
        if (direction == DIR_FIGURE_CAN_NOT_REACH || direction == DIR_FIGURE_REROUTE) {
            state = FIGURE_STATE_ALIVE;
            destination_tile = random_around_point(tile, tile, /*step*/2, /*bias*/4, /*max_dist*/8);
            direction = DIR_0_TOP_RIGHT;
            advance_action(FIGURE_ACTION_6_EMIGRANT_LEAVING);
        }
        break;

    case FIGURE_ACTION_6_EMIGRANT_LEAVING:
    case 10:
        wait_ticks--;
        if (wait_ticks > 0) {
            anim_frame = 0;
            break;
        }

        if (do_goto(exit, TERRAIN_USAGE_ANY)) {
            poof();
        }

        if (direction == DIR_FIGURE_CAN_NOT_REACH) {
            routing_try_reroute_counter++;
            if (routing_try_reroute_counter > 20) {
                poof();
                break;
            }
            wait_ticks = 20;
            route_remove();
            state = FIGURE_STATE_ALIVE;
            tile2i road_tile;
            map_closest_road_within_radius(exit, 1, 2, road_tile);
            destination_tile = road_tile;
            direction = DIR_0_TOP_RIGHT;
            advance_action(ACTION_16_EMIGRANT_RANDOM);
        }
        break;
    }

    {
        OZZY_PROFILER_SECTION("Game/Run/Tick/Figure/Emigrant/Update Image");
        update_direction_and_image();
    }
}

void figure::homeless_action() {
    OZZY_PROFILER_SECTION("Game/Run/Tick/Figure/Homeless");
    map_point& exit = city_map_exit_point();
    switch (action_state) {
    case FIGURE_ACTION_7_HOMELESS_CREATED:
        anim_frame = 0;
        wait_ticks++;
        if (wait_ticks > 51) {
            wait_ticks = 0;
            int building_id = closest_house_with_room(tile);
            if (building_id) {
                building* b = building_get(building_id);
                tile2i road_tile;
                if (map_closest_road_within_radius(b->tile, b->size, 2, road_tile)) {
                    b->set_figure(2, id);
                    set_immigrant_home(building_id);
                    advance_action(FIGURE_ACTION_8_HOMELESS_GOING_TO_HOUSE);
                } else {
                    poof();
                }
            } else {
                advance_action(FIGURE_ACTION_6_HOMELESS_LEAVING);
            }
        }
        break;

    case FIGURE_ACTION_8_HOMELESS_GOING_TO_HOUSE:
        if (!has_home()) {
            direction = DIR_0_TOP_RIGHT;
            advance_action(FIGURE_ACTION_6_HOMELESS_LEAVING);
        } else {
            do_gotobuilding(immigrant_home(), true, TERRAIN_USAGE_ANY, FIGURE_ACTION_9_HOMELESS_ENTERING_HOUSE);
        }
        break;

    case FIGURE_ACTION_9_HOMELESS_ENTERING_HOUSE:
        if (do_enterbuilding(false, immigrant_home())) {
            add_house_population(immigrant_home(), migrant_num_people);
        }
        //            is_ghost = in_building_wait_ticks ? 1 : 0;
        break;

    case ACTION_16_HOMELESS_RANDOM:
        roam_wander_freely = false;
        do_goto(destination_tile, TERRAIN_USAGE_ANY, FIGURE_ACTION_6_HOMELESS_LEAVING, FIGURE_ACTION_6_HOMELESS_LEAVING);
        if (direction == DIR_FIGURE_CAN_NOT_REACH || direction == DIR_FIGURE_REROUTE) {
            routing_try_reroute_counter++;
            if (routing_try_reroute_counter > 20) {
                poof();
                break;
            }
            state = FIGURE_STATE_ALIVE;
            destination_tile = random_around_point(tile, tile, /*step*/2, /*bias*/4, /*max_dist*/8);
            direction = DIR_0_TOP_RIGHT;
            advance_action(FIGURE_ACTION_6_HOMELESS_LEAVING);
        }
        break;

    case FIGURE_ACTION_6_HOMELESS_LEAVING:
        if (do_goto(exit, TERRAIN_USAGE_ANY)) {
            poof();
        }

        if (direction == DIR_FIGURE_CAN_NOT_REACH) {
            routing_try_reroute_counter++;
            if (routing_try_reroute_counter > 20) {
                poof();
                break;
            }
            wait_ticks = 20;
            route_remove();
            state = FIGURE_STATE_ALIVE;
            tile2i road_tile;
            map_closest_road_within_radius(exit, 1, 2, road_tile);
            destination_tile = road_tile;
            direction = DIR_0_TOP_RIGHT;
            advance_action(ACTION_16_HOMELESS_RANDOM);
        }

        wait_ticks++;
        if (wait_ticks > 30) {
            wait_ticks = 0;
            int building_id = closest_house_with_room(tile);
            if (building_id > 0) {
                building* b = building_get(building_id);
                map_point road_tile;
                if (map_closest_road_within_radius(b->tile, b->size, 2, road_tile)) {
                    b->set_figure(2, id);
                    set_immigrant_home(building_id);
                    advance_action(FIGURE_ACTION_8_HOMELESS_GOING_TO_HOUSE);
                }
            }
        }
        break;
    }
}
