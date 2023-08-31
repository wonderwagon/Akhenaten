#include "city_overlay_juggler.h"

#include "city_overlay.h"
#include "grid/property.h"
#include "grid/building.h"
#include "graphics/elements/tooltip.h"

static int get_column_height_bandstand(const building* b) {
    if (b->house_size) {
        if (b->data.house.bandstand_musician) {
            return b->data.house.bandstand_musician / 10;
        }
    }

    return NO_COLUMN;
}

static int get_tooltip_bandstand(tooltip_context* c, const building* b) {
    if (b->data.house.bandstand_musician <= 0)
        return 79;
    else if (b->data.house.bandstand_musician >= 80)
        return 80;
    else if (b->data.house.bandstand_musician >= 20)
        return 81;
    else {
        return 82;
    }
}

struct city_overlay_bandstand : public city_overlay {
    city_overlay_bandstand() {
        type = OVERLAY_BANDSTAND;
        column_type = COLUMN_TYPE_POSITIVE;

        get_column_height = get_column_height_bandstand;
        get_tooltip_for_building = get_tooltip_bandstand;
    }

    bool show_figure(const figure* f) const override {
        if (f->type == FIGURE_MUSICIAN) {
            return ((figure*)f)->get_entertainment_building()->type == BUILDING_BANDSTAND;
        }

        return false;
    }

    void draw_custom_top(vec2i pixel, map_point point) const override {
        int grid_offset = point.grid_offset();
        if (!map_property_is_draw_tile(grid_offset)) {
            return;
        }

        if (map_building_at(grid_offset)) {
            city_with_overlay_draw_building_top(pixel, point);
        }
    }

    bool show_building(const building *b) const override {
        return b->type == BUILDING_CONSERVATORY || b->type == BUILDING_BANDSTAND;
    }
};

city_overlay_bandstand g_city_overlay_bandstand;

const city_overlay* city_overlay_for_bandstand() {
    return &g_city_overlay_bandstand;
}
