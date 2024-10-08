#pragma once

#include "city_overlay.h"

struct city_overlay_physician : public city_overlay {
    city_overlay_physician();

    virtual int get_column_height(const building *b) const override;
    virtual int get_tooltip_for_building(tooltip_context *c, const building *b) const override;
};

city_overlay* city_overlay_for_physician();
