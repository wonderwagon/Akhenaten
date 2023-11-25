#include "translation/common.h"
#include "translation/translation.h"

static translation_string all_strings[] = {
     {TR_NO_PATCH_TITLE, "Patch 1.0.1.0 not installed"},
     {TR_NO_PATCH_MESSAGE,
      "Your Pharahoh installation does not have the 1.2.1.0 patch installed. "
      "You can download the patch from:\n" URL_PATCHES "\n"
      "Continue at your own risk."},
     {TR_MISSING_FONTS_TITLE, "Missing fonts"},
     {TR_MISSING_FONTS_MESSAGE,
      "Your Pharahoh installation requires extra font files. "
      "You can download them for your language from:\n" URL_PATCHES},
     {TR_NO_EDITOR_TITLE, "Editor not installed"},
     {TR_NO_EDITOR_MESSAGE,
      "Your Pharahoh installation does not contain the editor files. "
      "You can download them from:\n" URL_EDITOR},
     {TR_INVALID_LANGUAGE_TITLE, "Invalid language directory"},
     {TR_INVALID_LANGUAGE_MESSAGE,
      "The directory you selected does not contain a valid language pack. "
      "Please check the log for errors."},
     {TR_BUTTON_OK, "OK"},
     {TR_BUTTON_CANCEL, "Cancel"},
     {TR_BUTTON_RESET_DEFAULTS, "Reset defaults"},
     {TR_BUTTON_CONFIGURE_HOTKEYS, "Configure hotkeys"},
     {TR_BUTTON_NEXT, "+"},
     {TR_BUTTON_PREV, "-"},
     {TR_CONFIG_TITLE, "Enhanced settings"},
     {TR_CONFIG_LANGUAGE_LABEL, "Language:"},
     {TR_CONFIG_LANGUAGE_DEFAULT, "(default)"},
     {TR_CONFIG_PAGE_LABEL, "Page"},
     {TR_CONFIG_HEADER_UI_CHANGES, "User interface changes"},
     {TR_CONFIG_HEADER_GAMEPLAY_CHANGES, "Gameplay changes"},
     {TR_CONFIG_HEADER_GODS_CHANGES, "Gods changes"},
     {TR_CONFIG_HEADER_BUILDING_CHANGES, "Building changes"},
     {TR_CONFIG_HEADER_RESOURCE_CHANGES, "Resource changes"},
     {TR_CONFIG_SHOW_INTRO_VIDEO, "Play intro videos"},
     {TR_CONFIG_SIDEBAR_INFO, "Extra information in the control panel"},
     {TR_CONFIG_SMOOTH_SCROLLING, "Enable smooth scrolling"},
     {TR_CONFIG_VISUAL_FEEDBACK_ON_DELETE, "Improve visual feedback when clearing land"},
     {TR_CONFIG_ALLOW_CYCLING_TEMPLES, "Allow building each temple in succession"},
     {TR_CONFIG_SHOW_WATER_STRUCTURE_RANGE, "Show range when building reservoirs, fountains and wells"},
     {TR_CONFIG_SHOW_CONSTRUCTION_SIZE, "Show draggable construction size"},
     {TR_CONFIG_HIGHLIGHT_LEGIONS, "Highlight legion on cursor hover"},
     {TR_CONFIG_ROTATE_MANUALLY, "Rotate Gatehouse and Triumph Arch by hotkey"},
     {TR_CONFIG_FIX_IMMIGRATION_BUG, "Fix immigration bug on very hard"},
     {TR_CONFIG_FIX_100_YEAR_GHOSTS, "Fix 100-year-old ghosts"},
     {TR_CONFIG_FIX_EDITOR_EVENTS, "Fix Emperor change and survival time in custom missions"},
     {TR_CONFIG_DRAW_WALKER_WAYPOINTS, "Draw walker waypoints on overlay after right clicking on a building"},
     {TR_CONFIG_ZOOM_STEPPED, "Enable zoom (can be slow, uses more RAM)"},
     {TR_CONFIG_COMPLETE_RATING_COLUMNS, "Fix uncompleted rating columns on low targets"},
     {TR_CONFIG_GRANDFESTIVAL, "Grand festivals allow extra blessing from a god"},
     {TR_CONFIG_JEALOUS_GODS, "Disable jealousness of gods"},
     {TR_CONFIG_GLOBAL_LABOUR, "Enable global labour pool"},
     {TR_CONFIG_SCHOOL_WALKERS, "Extend school walkers range"},
     {TR_CONFIG_RETIRE_AT_60, "Change citizens' retirement age from 50 to 60"},
     {TR_CONFIG_FIXED_WORKERS, "Fixed worker pool - 38% of population"},
     {TR_CONFIG_EXTRA_FORTS, "Allow building 4 extra forts"},
     {TR_CONFIG_WOLVES_BLOCK, "Block building around wolves"},
     {TR_CONFIG_DYNAMIC_GRANARIES, "Block unconnected granary roads"},
     {TR_CONFIG_MORE_STOCKPILE, "Houses stockpile more goods from market"},
     {TR_CONFIG_NO_BUYER_DISTRIBUTION, "Buying market ladies don't distribute goods"},
     {TR_CONFIG_IMMEDIATELY_DELETE_BUILDINGS, "Immediately destroy buildings"},
     {TR_CONFIG_GETTING_GRANARIES_GO_OFFROAD, "Cart pushers from getting granaries can go offroad"},
     {TR_CONFIG_GRANARIES_GET_DOUBLE, "Double the capacity of cart pushers from getting granaries"},
     {TR_CONFIG_TOWER_SENTRIES_GO_OFFROAD, "Tower sentries don't need road access from barracks"},
     {TR_CONFIG_FARMS_DELIVER_CLOSE, "Farms and wharves deliver only to nearby granaries"},
     {TR_CONFIG_DELIVER_ONLY_TO_ACCEPTING_GRANARIES, "Food isn't delivered to getting granaries"},
     {TR_CONFIG_ALL_HOUSES_MERGE, "All houses merge"},
     {TR_CONFIG_WINE_COUNTS_IF_OPEN_TRADE_ROUTE, "Open trade route count as providing different wine type"},
     {TR_CONFIG_RANDOM_COLLAPSES_TAKE_MONEY, "Randomly collapsing clay pits and iron mines take some money instead"},
     {TR_CONFIG_MULTIPLE_BARRACKS, "Allow building multiple barracks."},
     {TR_CONFIG_NOT_ACCEPTING_WAREHOUSES, "Warehouses don't accept anything when built"},
     {TR_CONFIG_HOUSES_DONT_EXPAND_INTO_GARDENS, "Houses don't expand into gardens"},
     {TR_CONFIG_FIREMAN_RETURNING, "Fireman returning after fight fire"},
     {TR_CONFIG_CART_SPEED_DEPENDS_QUANTITY, "Cart speed depends from quantity resource"},
     {TR_CONFIG_CH_CITIZEN_ROAD_OFFSET, "Use different offsets for citizens in road"},
     {TR_CONFIG_CH_WORK_CAMP_ONE_WORKER_PER_MONTH, "Work camp spawn one worker per month"},
     {TR_CONFIG_CH_CLAY_PIT_FIRE_RISK_REDUCED, "Clay pit fire risk reduced"},
     {TR_CONFIG_CITY_HAS_ANIMALS, "City has animals" },
     {TR_CONFIG_GOLDMINE_TWICE_PRODUCTION, "Goldmine twice production"},
     {TR_CONFIG_NEW_TAX_COLLECTION_SYSTEM, "New tax collection system"},
     {TR_CONFIG_SMALL_HUT_NOT_CREATE_EMIGRANT, "Small hut houses not create enimgrant"},
     {TR_CONFIG_DELIVERY_BOY_GOES_TO_MARKET_ALONE, "Delivery boy goes to market alone"},
     {TR_CONFIG_RELIGION_COVERAGE_INFLUENCE_SENTIMENT, "Religion coverage influence sentiment"},
     {TR_CONFIG_MONUMENTS_INFLUENCE_SENTIMENT, "Monuments influence sentiment"},
     {TR_CONFIG_WELL_RADIUS_DEPENDS_MOISTURE, "Well radius depends from moisture"},
     {TR_CONFIG_ENTER_POINT_ON_NEAREST_TILE, "Building entrance on the neareast tile"},
     {TR_CONFIG_GOD_OSIRIS_DISABLED, "Osiris disabled"},
     {TR_CONFIG_GOD_RA_DISABLED, "Ra disabled"},
     {TR_CONFIG_GOD_PTAH_DISABLED, "Ptah disabled"},
     {TR_CONFIG_GOD_SETH_DISABLED, "Seth disabled"},
     {TR_CONFIG_GOD_BAST_DISABLED, "Bast disabled"},
     {TR_CONFIG_BUILDING_WOOD_CUTTER, "Wood cutter enabled"},
     {TR_CONFIG_BUILDING_COPPE_MINE, "Copper Mine enabled"},
     {TR_CONFIG_RESOURCE_TIMBER, "City produce timber"},
     {TR_CONFIG_RESOURCE_COPPER, "City produce copper"},
     {TR_CONFIG_BUILDING_REED_GATHERER, "Reed Gatherer enabled"},
     {TR_CONFIG_BUILDING_PAPYRUS_MAKER, "Papyrus Maker enabled"},
     {TR_CONFIG_BUILDING_SCRIBAL_SCHOOL, "Scribal School enabled"},
     {TR_CONFIG_BUILDING_SHIPYARD, "Shipyard enabled"},
     {TR_CONFIG_BUILDING_FISHING_WHARF, "Fishing wharf enabled"},
     {TR_CONFIG_BUILDING_CHICKPEAS_FARM, "Chickpeas farm enabled"},
     {TR_CONFIG_BUILDING_LETTUCE_FARM, "Lettuce farm enabled"},
     {TR_CONFIG_BUILDING_POMEGRANATES_FARM, "Pomegranates farm enabled"},
     {TR_CONFIG_BUILDING_FIGS_FARM, "Figs farm enabled"},
     {TR_CONFIG_BUILDING_GRAIN_FARM, "Grain farm enabled"},
     {TR_CONFIG_BUILDING_CATTLE_RANCH, "Cattle ranch enabled"},
     {TR_CONFIG_BUILDING_BRICKS_WORKSHOP, "Bricks workshop enabled"},
     {TR_CONFIG_BUILDING_WORK_CAMP, "Work camp enabled"},
     {TR_CONFIG_BUILDING_GOLD_MINE, "Gold mine enabled"},
     {TR_CONFIG_BUILDING_QUARRY_SANDSTONE, "Quarry sandstone enabled"},
     {TR_CONFIG_BUILDING_QUARRY_GRANITE, "Quarry granite enabled"},
     {TR_CONFIG_BUILDING_QUARRY_STONE, "Quarry stone enabled"},
     {TR_CONFIG_BUILDING_QUARRY_LIMESTONE, "Quarry limestone enabled"},
     {TR_CONFIG_BUILDING_CLAY_PIT, "Clay pit enabled"},
     {TR_CONFIG_BUILDING_WEAPON_WORKSHOP, "Weapon workshop enabled"},
     {TR_CONFIG_BUILDING_RECRUTER, "Recruter enabled"},
     {TR_CONFIG_FISHING_WHARF_SPAWN_BOATS, "Fishing wharf spawn boats"},
     {TR_CONFIG_CITY_FLOTSAM_ENABLED, "City flotsam enabled"},
     {TR_CONFIG_RESOURCE_REED, "City produce reed"},
     {TR_CONFIG_RESOURCE_PAPYRUS, "City produce papyrus"},
     {TR_CONFIG_RESOURCE_FISH, "City produce fish"},
     {TR_CONFIG_RESOURCE_CHICKPEAS, "City produce chickpeas"},
     {TR_CONFIG_RESOURCE_POMEGRANADES, "City produce pomegranades"},
     {TR_CONFIG_RESOURCE_LETTUCE, "City produce lettuce"},
     {TR_CONFIG_RESOURCE_FIGS, "City produce figs"},
     {TR_CONFIG_RESOURCE_GRAIN, "City produce grain"},
     {TR_CONFIG_RESOURCE_MEAT, "City produce meat"},
     {TR_CONFIG_RESOURCE_BRICKS, "City produce bricks"},
     {TR_CONFIG_RESOURCE_CLAY, "City produce clay"},
     {TR_CONFIG_COPPER_NEAR_MOUNTAINS, "Copper mine can build near mountains"},
     {TR_CONFIG_RECRUITER_NOT_NEED_FORTS, "Recruiter not need forts"},
     {TR_CONFIG_DRAW_FPS, "Draw FPS"},
     {TR_CONFIG_HIGHLIGHT_TOP_MENU_HOVER, "Highlight Top Menu Items"},
     {TR_CONFIG_EMPIRE_CITY_OLD_NAMES, "Show Old Names for city on empire map"},
     {TR_HOTKEY_TITLE, "Hotkeys configuration"},
     {TR_HOTKEY_LABEL, "Hotkey"},
     {TR_HOTKEY_ALTERNATIVE_LABEL, "Alternative"},
     {TR_HOTKEY_HEADER_ARROWS, "Arrow keys"},
     {TR_HOTKEY_HEADER_GLOBAL, "Global hotkeys"},
     {TR_HOTKEY_HEADER_CITY, "City hotkeys"},
     {TR_HOTKEY_HEADER_ADVISORS, "Advisors"},
     {TR_HOTKEY_HEADER_OVERLAYS, "Overlays"},
     {TR_HOTKEY_HEADER_BOOKMARKS, "City map bookmarks"},
     {TR_HOTKEY_HEADER_EDITOR, "Editor"},
     {TR_HOTKEY_HEADER_BUILD, "Construction hotkeys"},
     {TR_HOTKEY_ARROW_UP, "Up"},
     {TR_HOTKEY_ARROW_DOWN, "Down"},
     {TR_HOTKEY_ARROW_LEFT, "Left"},
     {TR_HOTKEY_ARROW_RIGHT, "Right"},
     {TR_HOTKEY_TOGGLE_FULLSCREEN, "Toggle fullscreen"},
     {TR_HOTKEY_CENTER_WINDOW, "Center window"},
     {TR_HOTKEY_RESIZE_TO_640, "Resize window to 640x480"},
     {TR_HOTKEY_RESIZE_TO_800, "Resize window to 800x600"},
     {TR_HOTKEY_RESIZE_TO_1024, "Resize window to 1024x768"},
     {TR_HOTKEY_SAVE_SCREENSHOT, "Save screenshot"},
     {TR_HOTKEY_SAVE_CITY_SCREENSHOT, "Save full city screenshot"},
     {TR_HOTKEY_LOAD_FILE, "Load file"},
     {TR_HOTKEY_SAVE_FILE, "Save file"},
     {TR_HOTKEY_INCREASE_GAME_SPEED, "Increase game speed"},
     {TR_HOTKEY_DECREASE_GAME_SPEED, "Decrease game speed"},
     {TR_HOTKEY_TOGGLE_PAUSE, "Toggle pause"},
     {TR_HOTKEY_CYCLE_LEGION, "Cycle through legions"},
     {TR_HOTKEY_ROTATE_MAP_LEFT, "Rotate map left"},
     {TR_HOTKEY_ROTATE_MAP_RIGHT, "Rotate map right"},
     {TR_HOTKEY_SHOW_ADVISOR_LABOR, "Labor advisor"},
     {TR_HOTKEY_SHOW_ADVISOR_MILITARY, "Military advisor"},
     {TR_HOTKEY_SHOW_ADVISOR_IMPERIAL, "Imperial advisor"},
     {TR_HOTKEY_SHOW_ADVISOR_RATINGS, "Ratings advisor"},
     {TR_HOTKEY_SHOW_ADVISOR_TRADE, "Trade advisor"},
     {TR_HOTKEY_SHOW_ADVISOR_POPULATION, "Population advisor"},
     {TR_HOTKEY_SHOW_ADVISOR_HEALTH, "Health advisor"},
     {TR_HOTKEY_SHOW_ADVISOR_EDUCATION, "Education advisor"},
     {TR_HOTKEY_SHOW_ADVISOR_ENTERTAINMENT, "Entertainment advisor"},
     {TR_HOTKEY_SHOW_ADVISOR_RELIGION, "Religion advisor"},
     {TR_HOTKEY_SHOW_ADVISOR_FINANCIAL, "Financial advisor"},
     {TR_HOTKEY_SHOW_ADVISOR_CHIEF, "Chief advisor"},
     {TR_HOTKEY_SHOW_ADVISOR_HOUSING, "Housing advisor"},
     {TR_HOTKEY_TOGGLE_OVERLAY, "Toggle current overlay"},
     {TR_HOTKEY_SHOW_OVERLAY_WATER, "Show water overlay"},
     {TR_HOTKEY_SHOW_OVERLAY_FIRE, "Show fire overlay"},
     {TR_HOTKEY_SHOW_OVERLAY_DAMAGE, "Damage overlay"},
     {TR_HOTKEY_SHOW_OVERLAY_CRIME, "Crime overlay"},
     {TR_HOTKEY_ROTATE_BUILDING, "Rotate building"},
     {TR_HOTKEY_SHOW_OVERLAY_PROBLEMS, "Problems overlay"},
     {TR_HOTKEY_GO_TO_BOOKMARK_1, "Go to bookmark 1"},
     {TR_HOTKEY_GO_TO_BOOKMARK_2, "Go to bookmark 2"},
     {TR_HOTKEY_GO_TO_BOOKMARK_3, "Go to bookmark 3"},
     {TR_HOTKEY_GO_TO_BOOKMARK_4, "Go to bookmark 4"},
     {TR_HOTKEY_SET_BOOKMARK_1, "Set bookmark 1"},
     {TR_HOTKEY_SET_BOOKMARK_2, "Set bookmark 2"},
     {TR_HOTKEY_SET_BOOKMARK_3, "Set bookmark 3"},
     {TR_HOTKEY_SET_BOOKMARK_4, "Set bookmark 4"},
     {TR_HOTKEY_EDITOR_TOGGLE_BATTLE_INFO, "Toggle battle info"},
     {TR_HOTKEY_EDIT_TITLE, "Press new hotkey"},
     {TR_BUILDING_ROADBLOCK, "Roadblock"},
     {TR_BUILDING_ROADBLOCK_DESC, "Roadblock stops loitering citizens."},
     {TR_HEADER_HOUSING, "Housing"},
     {TR_ADVISOR_HOUSING_ROOM, "City housing has room available for"},
     {TR_ADVISOR_HOUSING_NO_ROOM, "There is no room available in city housing."},
     {TR_ADVISOR_RESIDENCES_DEMANDING_POTTERY, "Residences demanding pottery"},
     {TR_ADVISOR_RESIDENCES_DEMANDING_FURNITURE, "Residences demanding furniture"},
     {TR_ADVISOR_RESIDENCES_DEMANDING_OIL, "Residences demanding oil"},
     {TR_ADVISOR_RESIDENCES_DEMANDING_WINE, "Residences demanding wine"},
     {TR_ADVISOR_TOTAL_NUM_HOUSES, "Total residences:"},
     {TR_ADVISOR_AVAILABLE_HOUSING_CAPACITY, "Available capacity:"},
     {TR_ADVISOR_TOTAL_HOUSING_CAPACITY, "Total capacity:"},
     {TR_ADVISOR_ADVISOR_HEADER_HOUSING, "Population - Housing"},
     {TR_ADVISOR_BUTTON_GRAPHS, "Graphs"},
     {TR_ADVISOR_HOUSING_PROSPERITY_RATING, "Housing prosperity rating is"},
     {TR_ADVISOR_PERCENTAGE_IN_MANORS, "Percentage of your population in villas and palaces is"},
     {TR_ADVISOR_PERCENTAGE_IN_SHANTIES, "Percentage of your population in tents and shacks is"},
     {TR_ADVISOR_AVERAGE_TAX, "Average tax income per residence is"},
     {TR_ADVISOR_AVERAGE_AGE, "Average age of your population is"},
     {TR_ADVISOR_PERCENT_IN_WORKFORCE, "Percentage of your population in the workforce is"},
     {TR_ADVISOR_BIRTHS_LAST_YEAR, "Births last year:"},
     {TR_ADVISOR_DEATHS_LAST_YEAR, "Deaths last year:"},
     {TR_ADVISOR_TOTAL_POPULATION, "residents total"}};

void translation_english(const translation_string** strings, int* num_strings) {
    *strings = all_strings;
    *num_strings = sizeof(all_strings) / sizeof(translation_string);
}
