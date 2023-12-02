#include "trade.h"

#include "building/count.h"
#include "city/constants.h"
#include "city/data_private.h"
#include "core/profiler.h"
#include "empire/empire_city.h"
#include "config/config.h"

void city_trade_update() {
    OZZY_PROFILER_SECTION("Game/Run/Tick/Trade Update");
    city_data.trade.num_sea_routes = 0;
    city_data.trade.num_land_routes = 0;
    // Wine types
    city_data.resource.wine_types_available = building_count_industry_total(RESOURCE_BEER) > 0 ? 1 : 0;
    if (city_data.resource.trade_status[RESOURCE_BEER] == TRADE_STATUS_IMPORT
        || config_get(CONFIG_GP_CH_WINE_COUNTS_IF_OPEN_TRADE_ROUTE)) {
        city_data.resource.wine_types_available += empire_city_count_wine_sources();
    }

    // Update trade problems
    if (city_data.trade.land_trade_problem_duration > 0) {
        city_data.trade.land_trade_problem_duration--;
    } else {
        city_data.trade.land_trade_problem_duration = 0;
    }

    if (city_data.trade.sea_trade_problem_duration > 0) {
        city_data.trade.sea_trade_problem_duration--;
    } else {
        city_data.trade.sea_trade_problem_duration = 0;
    }

    empire_city_generate_trader();
}

void city_trade_add_land_trade_route() {
    city_data.trade.num_land_routes++;
}

void city_trade_add_sea_trade_route() {
    city_data.trade.num_sea_routes++;
}

int city_trade_has_land_trade_route() {
    return city_data.trade.num_land_routes > 0;
}

int city_trade_has_sea_trade_route() {
    return city_data.trade.num_sea_routes > 0;
}

void city_trade_start_land_trade_problems(int duration) {
    city_data.trade.land_trade_problem_duration = duration;
}

void city_trade_start_sea_trade_problems(int duration) {
    city_data.trade.sea_trade_problem_duration = duration;
}

int city_trade_has_land_trade_problems() {
    return city_data.trade.land_trade_problem_duration > 0;
}

int city_trade_has_sea_trade_problems() {
    return city_data.trade.sea_trade_problem_duration > 0;
}

e_resource city_trade_current_caravan_import_resource() {
    return city_data.trade.caravan_import_resource;
}

e_resource city_trade_next_caravan_import_resource() {
    city_data.trade.caravan_import_resource = (e_resource)(city_data.trade.caravan_import_resource + 1);
    if (city_data.trade.caravan_import_resource >= RESOURCES_MAX)
        city_data.trade.caravan_import_resource = RESOURCE_MIN;

    return city_data.trade.caravan_import_resource;
}

e_resource city_trade_next_caravan_backup_import_resource() {
    city_data.trade.caravan_backup_import_resource = (e_resource)(city_data.trade.caravan_backup_import_resource + 1);
    if (city_data.trade.caravan_backup_import_resource >= RESOURCES_MAX)
        city_data.trade.caravan_backup_import_resource = RESOURCE_MIN;

    return city_data.trade.caravan_backup_import_resource;
}

e_resource city_trade_next_docker_import_resource() {
    city_data.trade.docker_import_resource = (e_resource)(city_data.trade.docker_import_resource + 1);
    if (city_data.trade.docker_import_resource >= RESOURCES_MAX)
        city_data.trade.docker_import_resource = RESOURCE_MIN;

    return city_data.trade.docker_import_resource;
}

e_resource city_trade_next_docker_export_resource() {
    city_data.trade.docker_export_resource = (e_resource)(city_data.trade.docker_export_resource + 1);
    if (city_data.trade.docker_export_resource >= RESOURCES_MAX)
        city_data.trade.docker_export_resource = RESOURCE_MIN;

    return city_data.trade.docker_export_resource;
}
