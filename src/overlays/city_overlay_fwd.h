#pragma once

enum e_column_type {
    COLUMN_TYPE_RISK,
    COLUMN_TYPE_POSITIVE,
    COLUMN_TYPE_WATER_ACCESS
};

enum e_column_color {
    COLUMN_COLOR_PLAIN = 0,
    COLUMN_COLOR_YELLOW = 3,
    COLUMN_COLOR_ORANGE = 6,
    COLUMN_COLOR_RED = 9,
    COLUMN_COLOR_BLUE = 12,
};

enum e_overlay {
    OVERLAY_NONE = 0,
    OVERLAY_WATER = 2,
    OVERLAY_RELIGION = 4,
    OVERLAY_FIRE = 8,
    OVERLAY_DAMAGE = 9,
    OVERLAY_CRIME = 10,
    OVERLAY_ENTERTAINMENT = 11,
    OVERLAY_BOOTH = 12,
    OVERLAY_BANDSTAND = 13,
    OVERLAY_PAVILION = 14,
    OVERLAY_HIPPODROME = 15,
    OVERLAY_EDUCATION = 16,
    OVERLAY_SCHOOL = 17,
    OVERLAY_LIBRARY = 18,
    OVERLAY_ACADEMY = 19,
    OVERLAY_APOTHECARY = 20,
    OVERLAY_DENTIST = 21,
    OVERLAY_PHYSICIAN = 22,
    OVERLAY_MORTUARY = 23,
    OVERLAY_TAX_INCOME = 24,
    OVERLAY_FOOD_STOCKS = 25,
    OVERLAY_DESIRABILITY = 26,
    OVERLAY_WORKERS_UNUSED = 27,
    OVERLAY_NATIVE = 28,
    OVERLAY_PROBLEMS = 29,
    OVERLAY_RELIGION_OSIRIS = 30,
    OVERLAY_RELIGION_RA = 31,
    OVERLAY_RELIGION_PTAH = 32,
    OVERLAY_RELIGION_SETH = 33,
    OVERLAY_RELIGION_BAST = 34,
    OVERLAY_FERTILITY = 35,
    OVERLAY_BAZAAR_ACCESS = 36,
    OVERLAY_ROUTING = 37,
    OVERLAY_HEALTH = 38,
    OVERLAY_LABOR = 39,
    OVERLAY_COUTHOUSE = 40
};