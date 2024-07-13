#include "empire.h"

#include "core/game_environment.h"
#include "empire/empire.h"
#include "empire/empire_map.h"
#include "empire/empire_object.h"
#include "empire/trade_route.h"
#include "empire/type.h"
#include "graphics/image.h"
#include "graphics/graphics.h"
#include "graphics/elements/arrow_button.h"
#include "graphics/elements/generic_button.h"
#include "graphics/elements/lang_text.h"
#include "graphics/image_groups.h"
#include "graphics/screen.h"
#include "graphics/text.h"
#include "graphics/window.h"
#include "input/input.h"
#include "input/scroll.h"
#include "scenario/editor.h"
#include "scenario/empire.h"
#include "window/editor/map.h"
#include "game/game.h"

const static int EMPIRE_WIDTH[2] = {
  2000 + 32,
  1200 + 32,
};
const static int EMPIRE_HEIGHT[2] = {
  1000 + 136,
  1600 + 136 + 20,
};

static void button_change_empire(int is_up, int param2);
static void button_ok(int param1, int param2);

static arrow_button arrow_buttons_empire[]
  = {{8, 48, 17, 24, button_change_empire, 1, 0}, {32, 48, 15, 24, button_change_empire, 0, 0}};
static generic_button generic_button_ok[] = {{84, 48, 100, 24, button_ok, button_none, 0, 0}};

static struct {
    int selected_button;
    int selected_city;
    int x_min, x_max, y_min, y_max;
    vec2i draw_offset;
    int focus_button_id;
    int is_scrolling;
    int finished_scroll;
    int show_battle_objects;
} data;

static void init(void) {
    data.selected_button = 0;
    int selected_object = g_empire_map.selected_object();
    if (selected_object)
        data.selected_city = g_empire.get_city_for_object(selected_object - 1);
    else {
        data.selected_city = 0;
    }
    data.focus_button_id = 0;
}

static int map_viewport_width() {
    return data.x_max - data.x_min - 32;
}

static int map_viewport_height() {
    return data.y_max - data.y_min - 136;
}

static void draw_paneling() {
    painter ctx = game.painter();
    int image_base = image_id_from_group(GROUP_EDITOR_EMPIRE_PANELS);
    // bottom panel background
    graphics_set_clip_rectangle(data.x_min, data.y_min, data.x_max - data.x_min, data.y_max - data.y_min);
    for (int x = data.x_min; x < data.x_max; x += 70) {
        ImageDraw::img_generic(ctx, image_base + 3, vec2i{x, data.y_max - 120});
        ImageDraw::img_generic(ctx, image_base + 3, vec2i{x, data.y_max - 80});
        ImageDraw::img_generic(ctx, image_base + 3, vec2i{x, data.y_max - 40});
    }

    // horizontal bar borders
    for (int x = data.x_min; x < data.x_max; x += 86) {
        ImageDraw::img_generic(ctx, image_base + 1, vec2i{x, data.y_min});
        ImageDraw::img_generic(ctx, image_base + 1, vec2i{x, data.y_max - 120});
        ImageDraw::img_generic(ctx, image_base + 1, vec2i{x, data.y_max - 16});
    }

    // vertical bar borders
    for (int y = data.y_min + 16; y < data.y_max; y += 86) {
        ImageDraw::img_generic(ctx, image_base, vec2i{data.x_min, y});
        ImageDraw::img_generic(ctx, image_base, vec2i{data.x_max - 16, y});
    }

    // crossbars
    ImageDraw::img_generic(ctx, image_base + 2, vec2i{data.x_min, data.y_min});
    ImageDraw::img_generic(ctx, image_base + 2, vec2i{data.x_min, data.y_max - 120});
    ImageDraw::img_generic(ctx, image_base + 2, vec2i{data.x_min, data.y_max - 16});
    ImageDraw::img_generic(ctx, image_base + 2, vec2i{data.x_max - 16, data.y_min});
    ImageDraw::img_generic(ctx, image_base + 2, vec2i{data.x_max - 16, data.y_max - 120});
    ImageDraw::img_generic(ctx, image_base + 2, vec2i{data.x_max - 16, data.y_max - 16});

    graphics_reset_clip_rectangle();
}

static void draw_background(void) {
    int s_width = screen_width();
    int s_height = screen_height();
    data.x_min = s_width <= EMPIRE_WIDTH[GAME_ENV] ? 0 : (s_width - EMPIRE_WIDTH[GAME_ENV]) / 2;
    data.x_max = s_width <= EMPIRE_WIDTH[GAME_ENV] ? s_width : data.x_min + EMPIRE_WIDTH[GAME_ENV];
    data.y_min = s_height <= EMPIRE_HEIGHT[GAME_ENV] ? 0 : (s_height - EMPIRE_HEIGHT[GAME_ENV]) / 2;
    data.y_max = s_height <= EMPIRE_HEIGHT[GAME_ENV] ? s_height : data.y_min + EMPIRE_HEIGHT[GAME_ENV];

    if (data.x_min || data.y_min)
        graphics_clear_screen();

    draw_paneling();
}

static void draw_shadowed_number(int value, int x, int y, color color) {
    return;
    //    text_draw_number_colored(value, '@', " ", x + 1, y - 1, FONT_SMALL_PLAIN, COLOR_BLACK);
    //    text_draw_number_colored(value, '@', " ", x, y, FONT_SMALL_PLAIN, color);
}

static void draw_empire_object(const empire_object* obj) {
    painter ctx = game.painter();
    vec2i pos = obj->pos;
    int image_id = obj->image_id;

    if (!data.show_battle_objects
        && (obj->type == EMPIRE_OBJECT_BATTLE_ICON || obj->type == EMPIRE_OBJECT_KINGDOME_ARMY || obj->type == EMPIRE_OBJECT_ENEMY_ARMY)) {
        return;
    }

    if (obj->type == EMPIRE_OBJECT_CITY) {
        int city_id = g_empire.get_city_for_object(obj->id);
        const empire_city* city = g_empire.city(city_id);
        if (city->type == EMPIRE_CITY_EGYPTIAN || city->type == EMPIRE_CITY_FOREIGN) {
            image_id = image_id_from_group(GROUP_EDITOR_EMPIRE_FOREIGN_CITY);
        }
    } else if (obj->type == EMPIRE_OBJECT_BATTLE_ICON) {
        draw_shadowed_number(obj->invasion_path_id, data.draw_offset.x + pos.x - 9, data.draw_offset.y + pos.y - 9, COLOR_WHITE);
        draw_shadowed_number(obj->invasion_years, data.draw_offset.x + pos.x + 15, data.draw_offset.y + pos.y - 9, COLOR_FONT_RED);
    } else if (obj->type == EMPIRE_OBJECT_KINGDOME_ARMY || obj->type == EMPIRE_OBJECT_ENEMY_ARMY) {
        draw_shadowed_number(obj->distant_battle_travel_months, data.draw_offset.x + pos.x + 7, data.draw_offset.y + pos.y - 9, obj->type == EMPIRE_OBJECT_KINGDOME_ARMY ? COLOR_WHITE : COLOR_FONT_RED);
    }
    ImageDraw::img_generic(ctx, image_id, vec2i{data.draw_offset.x + pos.x, data.draw_offset.y + pos.y});
    const image_t* img = image_get(image_id);
    if (img->animation.speed_id) {
        int new_animation = empire_object_update_animation(obj, image_id);
        ImageDraw::img_generic(ctx, image_id + new_animation, data.draw_offset + pos + img->animation.sprite_offset);
    }
}

static void window_editor_draw_map() {
    painter ctx = game.painter();
    int viewport_width = map_viewport_width();
    int viewport_height = map_viewport_height();
    graphics_set_clip_rectangle(data.x_min + 16, data.y_min + 16, viewport_width, viewport_height);

    g_empire_map.set_viewport(vec2i(viewport_width, viewport_height));

    data.draw_offset.x = data.x_min + 16;
    data.draw_offset.y = data.y_min + 16;
    data.draw_offset = g_empire_map.adjust_scroll(data.draw_offset);
    ImageDraw::img_generic(ctx, image_id_from_group(GROUP_EDITOR_EMPIRE_MAP), data.draw_offset);

    empire_object_foreach(draw_empire_object);

    graphics_reset_clip_rectangle();
}

static void draw_resource(int resource, int trade_max, int x_offset, int y_offset) {
    painter ctx = game.painter();
    graphics_draw_inset_rect(vec2i{x_offset, y_offset}, vec2i{26, 26});
    int image_id = resource + image_id_from_group(GROUP_EDITOR_EMPIRE_RESOURCES);
    int resource_offset = resource_image_offset(resource, RESOURCE_IMAGE_ICON);
    ImageDraw::img_generic(ctx, image_id + resource_offset, vec2i{x_offset + 1, y_offset + 1});
    switch (trade_max) {
    case 15:
        ImageDraw::img_generic(ctx, image_id_from_group(GROUP_EDITOR_TRADE_AMOUNT), vec2i{x_offset + 21, y_offset - 1});
        break;
    case 25:
        ImageDraw::img_generic(ctx, image_id_from_group(GROUP_EDITOR_TRADE_AMOUNT) + 1, vec2i{x_offset + 17, y_offset - 1});
        break;
    case 40:
        ImageDraw::img_generic(ctx, image_id_from_group(GROUP_EDITOR_TRADE_AMOUNT) + 2, vec2i{x_offset + 13, y_offset - 1});
        break;
    }
}

static void draw_city_info(const empire_city* city) {
    int x_offset = data.x_min + 28;
    int y_offset = data.y_max - 85;

    int width = lang_text_draw(21, city->name_id, x_offset, y_offset, FONT_NORMAL_WHITE_ON_DARK);

    switch (city->type) {
    case EMPIRE_CITY_OURS:
    case EMPIRE_CITY_FOREIGN_TRADING:
        lang_text_draw(47, 12, x_offset + 20 + width, y_offset, FONT_NORMAL_BLACK_ON_DARK);
        break;

    case EMPIRE_CITY_EGYPTIAN_TRADING:
    case EMPIRE_CITY_EGYPTIAN:
    case EMPIRE_CITY_FOREIGN:
        lang_text_draw(47, 0, x_offset + 20 + width, y_offset, FONT_NORMAL_BLACK_ON_DARK);
        break;

    case EMPIRE_CITY_PHARAOH_TRADING: {
        width += lang_text_draw(47, 1, x_offset + 20 + width, y_offset, FONT_NORMAL_BLACK_ON_DARK);
        int resource_x_offset = x_offset + 30 + width;
        for (e_resource r = RESOURCE_MIN; r < RESOURCES_MAX; ++r) {
            if (empire_object_city_sells_resource(city->empire_object_id, r)) {
                draw_resource(r, 0, resource_x_offset, y_offset - 9);
                resource_x_offset += 32;
            }
        }
        break;
    }
    case EMPIRE_CITY_PHARAOH: {
        width += lang_text_draw(47, 5, x_offset + 20 + width, y_offset, FONT_NORMAL_BLACK_ON_DARK);
        int resource_x_offset = x_offset + 30 + width;
        for (const auto &r: resource_list::all) {
            if (empire_object_city_sells_resource(city->empire_object_id, r.type)) {
                int limit = city->get_route().limit(r.type);
                draw_resource(r.type, limit, resource_x_offset, y_offset - 9);
                resource_x_offset += 32;
            }
        }
        resource_x_offset += 50;
        resource_x_offset += lang_text_draw(47, 4, resource_x_offset, y_offset, FONT_NORMAL_BLACK_ON_DARK);
        resource_x_offset += 10;
        for (const auto &r: resource_list::all) {
            if (empire_object_city_buys_resource(city->empire_object_id, r.type)) {
                int limit = city->get_route().limit(r.type);
                draw_resource(r.type, limit, resource_x_offset, y_offset - 9);
                resource_x_offset += 32;
            }
        }
        break;
    }
    }
}

static void draw_panel_buttons(const empire_city* city) {
    arrow_buttons_draw({data.x_min + 20, data.y_max - 100}, arrow_buttons_empire, 2);

    if (city)
        draw_city_info(city);
    else {
        lang_text_draw_centered(150, scenario_empire_id(), data.x_min, data.y_max - 85, data.x_max - data.x_min, FONT_NORMAL_BLACK_ON_DARK);
    }
    lang_text_draw(151, scenario_empire_id(), data.x_min + 220, data.y_max - 45, FONT_NORMAL_BLACK_ON_DARK);

    button_border_draw(data.x_min + 104, data.y_max - 52, 100, 24, data.focus_button_id == 1);
    lang_text_draw_centered(44, 7, data.x_min + 104, data.y_max - 45, 100, FONT_NORMAL_BLACK_ON_DARK);
}

static void draw_foreground(void) {
    window_editor_draw_map();

    const empire_city* city = 0;
    int selected_object = g_empire_map.selected_object();
    if (selected_object) {
        const empire_object* object = empire_object_get(selected_object - 1);
        if (object->type == EMPIRE_OBJECT_CITY) {
            data.selected_city = g_empire.get_city_for_object(object->id);
            city = g_empire.city(data.selected_city);
        }
    }
    draw_panel_buttons(city);
}

static int is_outside_map(int x, int y) {
    return (x < data.x_min + 16 || x >= data.x_max - 16 || y < data.y_min + 16 || y >= data.y_max - 120);
}

static void determine_selected_object(const mouse* m) {
    if (!m->left.went_up || data.finished_scroll || is_outside_map(m->x, m->y)) {
        data.finished_scroll = 0;
        return;
    }
    g_empire_map.select_object(vec2i{m->x - data.x_min - 16, m->y - data.y_min - 16});
    window_invalidate();
}

static void handle_input(const mouse* m, const hotkeys* h) {
    vec2i position;
    if (scroll_get_delta(m, &position, SCROLL_TYPE_EMPIRE)) {
        g_empire_map.scroll_map(position);
    }

    if (h->toggle_editor_battle_info)
        data.show_battle_objects = !data.show_battle_objects;

    if (m->is_touch) {
        const touch* t = get_earliest_touch();
        if (!is_outside_map(t->current_point.x, t->current_point.y)) {
            if (t->has_started) {
                data.is_scrolling = 1;
                scroll_drag_start(1);
            }
        }
        if (t->has_ended) {
            data.is_scrolling = 0;
            data.finished_scroll = !touch_was_click(t);
            scroll_drag_end();
        }
    }
    data.focus_button_id = 0;
    if (!arrow_buttons_handle_mouse(m, {data.x_min + 20, data.y_max - 100}, arrow_buttons_empire, 2, 0)) {
        if (!generic_buttons_handle_mouse(m, {data.x_min + 20, data.y_max - 100}, generic_button_ok, 1, &data.focus_button_id)) {
            determine_selected_object(m);
            int selected_object = g_empire_map.selected_object();
            if (selected_object) {
                if (empire_object_get(selected_object - 1)->type == EMPIRE_OBJECT_CITY)
                    data.selected_city = g_empire.get_city_for_object(selected_object - 1);

            } else if (input_go_back_requested(m, h))
                window_editor_map_show();
        }
    }
}

static void button_change_empire(int is_down, int param2) {
    scenario_editor_change_empire(is_down ? -1 : 1);
    empire_load_editor(scenario_empire_id(), map_viewport_width(), map_viewport_height());
    window_request_refresh();
}

static void button_ok(int param1, int param2) {
    window_editor_map_show();
}

void window_editor_empire_show(void) {
    window_type window = {WINDOW_EDITOR_EMPIRE, draw_background, draw_foreground, handle_input};
    init();
    window_show(&window);
}
