#include "js_constants.h"

#include "js_defines.h"

#include "input/hotkey.h"
#include "mujs/mujs.h"
#include "window/file_dialog.h"
#include "overlays/city_overlay_fwd.h"
#include "building/building.h"
#include "graphics/image_desc.h"
#include "graphics/image_groups.h"

#include "sound/city.h"

void js_register_game_constants(js_State *J) {
   REGISTER_GLOBAL_CONSTANT(J, FILE_TYPE_SAVED_GAME);
   REGISTER_GLOBAL_CONSTANT(J, FILE_DIALOG_LOAD);
}

void js_register_city_images(js_State *J) {
   REGISTER_GLOBAL_CONSTANT(J, IMG_NONE);
   REGISTER_GLOBAL_CONSTANT(J, IMG_IMMIGRANT);
   REGISTER_GLOBAL_CONSTANT(J, IMG_EMIGRANT);
   REGISTER_GLOBAL_CONSTANT(J, IMG_HOMELESS);
   REGISTER_GLOBAL_CONSTANT(J, IMG_FISHIHG_WHARF_ANIM);
   REGISTER_GLOBAL_CONSTANT(J, IMG_CARTPUSHER);
   REGISTER_GLOBAL_CONSTANT(J, IMG_CARTPUSHER_DEATH);
   REGISTER_GLOBAL_CONSTANT(J, IMG_FISHING_BOAT);
   REGISTER_GLOBAL_CONSTANT(J, IMG_FISHING_BOAT_WORK);
   REGISTER_GLOBAL_CONSTANT(J, IMG_FISHING_BOAT_DEATH);
   REGISTER_GLOBAL_CONSTANT(J, IMG_FISHING_BOAT_IDLE);
   REGISTER_GLOBAL_CONSTANT(J, IMG_FLOTSAM);
   REGISTER_GLOBAL_CONSTANT(J, IMG_LABOR_SEEKER);
   REGISTER_GLOBAL_CONSTANT(J, IMG_LABOR_SEEKER_DEATH);
   REGISTER_GLOBAL_CONSTANT(J, IMG_FISHING_POINT);
   REGISTER_GLOBAL_CONSTANT(J, IMG_FISHING_POINT_BUBLES);
   REGISTER_GLOBAL_CONSTANT(J, IMG_ENGINEER);
   REGISTER_GLOBAL_CONSTANT(J, IMG_ENGINEER_DEATH);
   REGISTER_GLOBAL_CONSTANT(J, IMG_WATER_SUPPLY);
   REGISTER_GLOBAL_CONSTANT(J, IMG_WATER_SUPPLY_FANCY);
   REGISTER_GLOBAL_CONSTANT(J, IMG_WELL);
   REGISTER_GLOBAL_CONSTANT(J, IMG_WELL_FANCY);
   REGISTER_GLOBAL_CONSTANT(J, IMG_EXPLOSION);
   REGISTER_GLOBAL_CONSTANT(J, IMG_CATTLE_RANCH);
   REGISTER_GLOBAL_CONSTANT(J, IMG_TAX_COLLECTOR);
   REGISTER_GLOBAL_CONSTANT(J, IMG_BRICKS_WORKSHOP);
   REGISTER_GLOBAL_CONSTANT(J, IMG_RESOURCE_GAMEMEAT);
   REGISTER_GLOBAL_CONSTANT(J, IMG_RESOURCE_CLAY);
   REGISTER_GLOBAL_CONSTANT(J, IMG_RESOURCE_STRAW);
   REGISTER_GLOBAL_CONSTANT(J, IMG_OSTRICH_WALK);
}

void js_register_collection_images(js_State *J) {
   REGISTER_GLOBAL_CONSTANT(J, PACK_UNLOADED);
   REGISTER_GLOBAL_CONSTANT(J, PACK_TERRAIN);
   REGISTER_GLOBAL_CONSTANT(J, PACK_GENERAL);
   REGISTER_GLOBAL_CONSTANT(J, PACK_SPR_MAIN);
   REGISTER_GLOBAL_CONSTANT(J, PACK_SPR_AMBIENT);
   REGISTER_GLOBAL_CONSTANT(J, PACK_EMPIRE);
   REGISTER_GLOBAL_CONSTANT(J, PACK_FONT);
   REGISTER_GLOBAL_CONSTANT(J, PACK_TEMPLE);
   REGISTER_GLOBAL_CONSTANT(J, PACK_MONUMENT);
   REGISTER_GLOBAL_CONSTANT(J, PACK_ENEMY)
   REGISTER_GLOBAL_CONSTANT(J, PACK_EXPANSION);
   REGISTER_GLOBAL_CONSTANT(J, PACK_EXPANSION_SPR);
}

void js_register_city_walkers(js_State *J) {
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_NONE);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_IMMIGRANT);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_EMIGRANT);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_HOMELESS);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_CART_PUSHER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_LABOR_SEEKER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_EXPLOSION);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_TAX_COLLECTOR);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ENGINEER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_STORAGE_YARD_DELIVERCART);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_FIREMAN);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_FORT_ARCHER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_FORT_SPEARMAN);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_FORT_CHARIOT);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_FORT_STANDARD);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_JUGGLER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_MUSICIAN);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_DANCER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_CHARIOTEER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_TRADE_CARAVAN);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_TRADE_SHIP);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_TRADE_CARAVAN_DONKEY);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_PROTESTER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_CRIMINAL);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_RIOTER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_FISHING_BOAT);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_MARKET_TRADER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_PRIEST);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_TEACHER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_SCRIBER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_LIBRARIAN);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_DENTIST);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_PHYSICIAN);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_HERBALIST);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_EMBALMER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_WORKER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_MAP_FLAG);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_FLOTSAM);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_DOCKER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_MARKET_BUYER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_NOBLES);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_INDIGENOUS_NATIVE);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_TOWER_SENTRY);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ENEMY43_SPEAR);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ENEMY44_SWORD);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ENEMY45_SWORD);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ENEMY46_CAMEL);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ENEMY47_ELEPHANT);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ENEMY48_CHARIOT);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ENEMY49_FAST_SWORD);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ENEMY50_SWORD);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ENEMY51_SPEAR);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ENEMY52_MOUNTED_ARCHER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ENEMY53_AXE);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ENEMY54_GLADIATOR);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ENEMY_CAESAR_JAVELIN);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ENEMY_CAESAR_MOUNTED);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ENEMY_CAESAR_LEGIONARY);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_NATIVE_TRADER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ARROW);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_JAVELIN);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_BOLT);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_BALLISTA);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_CREATURE);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_MISSIONARY);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_FISHING_POINT);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_DELIVERY_BOY);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_SHIPWRECK);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_SHEEP);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_OSTRICH);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_ZEBRA);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_SPEAR);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_HIPPODROME_HORSES);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_OSTRICH_HUNTER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_HUNTER_ARROW);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_LUMBERJACK);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_PHARAOH);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_GOVERNOR);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_78);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_CROCODILE);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_HIPPO);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_WORKER_PH);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_WATER_CARRIER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_POLICEMAN);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_MAGISTRATE);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_REED_GATHERER);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_FESTIVAL_PRIEST);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_92);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_93);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_FISHING_SPOT);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_100);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_101);
   REGISTER_GLOBAL_CONSTANT(J, FIGURE_HYENA);
}

void js_register_city_sound_constants(js_State *J) {
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_HOUSE_SLUM);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_HOUSE_POOR);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_HOUSE_MEDIUM);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_HOUSE_GOOD);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_HOUSE_POSH);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_BOOTH);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_BANDSTAND);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_PAVILION);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_SENET_HOUSE);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_JUGGLER_SCHOOL);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_DANCE_SCHOOL);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_CONSERVATORY);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_GARDEN);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_APOTHECARY);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_PHYSICIAN);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_MORTUARY);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_TOWER);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_TEMPLE_OSIRIS);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_TEMPLE_RA);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_TEMPLE_PTAH);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_TEMPLE_SETH);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_TEMPLE_BAST);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_SHRINE_OSIRIS);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_SHRINE_RA);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_SHRINE_PTAH);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_SHRINE_SETH);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_SHRINE_BAST);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_MARKET);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_GRANARY);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_STORAGE_YARD);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_SHIPYARD);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_DOCK);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_WHARF);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_PALACE);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_ENGINEERS_POST);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_FORUM);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_WATER_SUPPLY);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_WELL);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_BURNING_RUIN);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_GRAIN_FARM);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_FIG_FARM);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_QUARRY);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_GOLD_MINE);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_TIMBER_YARD);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_CLAY_PIT);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_WEAPONS_WORKSHOP);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_POTTERY_WORKSHOP);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_EMPTY_LAND);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_RIVER);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_HUNTER_LOUDGE);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_POLICE);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_ROCK);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_STATUE);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_TAX_COLLECTOR);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_DENTIST);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_MANSION);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_TREE);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_WATER);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_SHRUB);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_CANAL);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_MEADOW);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_FLOODPLAIN);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_MARSHLAND);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_CHICKFARM);
   REGISTER_GLOBAL_CONSTANT(J, SOUND_CHANNEL_CITY_COWFARM);
}

void js_register_city_buildings(js_State *J) {
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_NONE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MENU_FARMS);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MENU_RAW_MATERIALS);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MENU_GUILDS);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_ROAD);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_WALL);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_IRRIGATION_DITCH);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_CLEAR_LAND);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_VACANT_LOT);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_CRUDE_HUT);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_STURDY_HUT);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_MEAGER_SHANTY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_COMMON_SHANTY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_ROUGH_COTTAGE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_ORDINARY_COTTAGE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_MODEST_HOMESTEAD);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_SPACIOUS_HOMESTEAD);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_MODEST_APARTMENT);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_SPACIOUS_APARTMENT);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_COMMON_RESIDENCE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_SPACIOUS_RESIDENCE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_ELEGANT_RESIDENCE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_FANCY_RESIDENCE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_COMMON_MANOR);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_GRAND_VILLA);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_SMALL_PALACE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_MEDIUM_PALACE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_LARGE_PALACE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HOUSE_LUXURY_PALACE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_BANDSTAND);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_BOOTH);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_SENET_HOUSE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_PAVILLION);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_CONSERVATORY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_DANCE_SCHOOL);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_JUGGLER_SCHOOL);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_CHARIOT_MAKER);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_PLAZA);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_GARDENS);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_FORT_CHARIOTEERS);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_SMALL_STATUE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MEDIUM_STATUE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_LARGE_STATUE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_FORT_ARCHERS);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_FORT_INFANTRY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_APOTHECARY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MORTUARY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MENU_MONUMENTS);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_DENTIST);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_DISTRIBUTION_CENTER_UNUSED);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_SCRIBAL_SCHOOL);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_ACADEMY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_LIBRARY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_FORT_GROUND);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_POLICE_STATION);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TRIUMPHAL_ARCH);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MENU_FORTS);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_GATEHOUSE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TOWER);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TEMPLE_OSIRIS);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TEMPLE_RA);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TEMPLE_PTAH);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TEMPLE_SETH);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TEMPLE_BAST);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TEMPLE_COMPLEX_OSIRIS);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TEMPLE_COMPLEX_RA);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TEMPLE_COMPLEX_PTAH);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TEMPLE_COMPLEX_SETH);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TEMPLE_COMPLEX_BAST);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MARKET);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_GRANARY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_STORAGE_YARD);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_STORAGE_YARD_SPACE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_SHIPYARD);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_DOCK);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_FISHING_WHARF);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_PERSONAL_MANSION);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_FAMILY_MANSION);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_DYNASTY_MANSION);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MISSION_POST);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_ENGINEERS_POST);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_LOW_BRIDGE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_SHIP_BRIDGE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_GREATE_PALACE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_GREATE_PALACE_UPGRADED);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TAX_COLLECTOR);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TAX_COLLECTOR_UPGRADED);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_NATIVE_HUT);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_NATIVE_MEETING);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_WATER_LIFT);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MENU_BEAUTIFICATION);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_WELL);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_NATIVE_CROPS);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MILITARY_ACADEMY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_RECRUITER);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MENU_TEMPLES);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MENU_TEMPLE_COMPLEX);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_ORACLE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_BURNING_RUIN);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_BARLEY_FARM);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_FLAX_FARM);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_GRAIN_FARM);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_LETTUCE_FARM);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_POMEGRANATES_FARM);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_CHICKPEAS_FARM);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_STONE_QUARRY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_LIMESTONE_QUARRY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_WOOD_CUTTERS);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_CLAY_PIT);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_BEER_WORKSHOP);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_LINEN_WORKSHOP);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_WEAPONS_WORKSHOP);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_JEWELS_WORKSHOP);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_POTTERY_WORKSHOP);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HUNTING_LODGE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MENU_WATER_CROSSING);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_FERRY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_ROADBLOCK);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_SHRINE_OSIRIS);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_SHRINE_RA);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_SHRINE_PTAH);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_SHRINE_SETH);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_SHRINE_BAST);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MENU_SHRINES);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_GOLD_MINE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_GEMSTONE_MINE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_FIREHOUSE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_WALL_PH);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_GATEHOUSE_PH);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TOWER_PH);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MENU_DEFENSES);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_CARPENTERS_GUILD);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_BRICKLAYERS_GUILD);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_STONEMASONS_GUILD);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_WATER_SUPPLY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TRANSPORT_WHARF);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_WARSHIP_WHARF);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_PYRAMID);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_COURTHOUSE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_VILLAGE_PALACE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TOWN_PALACE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_CITY_PALACE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_CATTLE_RANCH);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_REED_GATHERER);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_FIGS_FARM);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_WORK_CAMP);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_GATEHOUSE_PH2);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_PAPYRUS_WORKSHOP);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_BRICKS_WORKSHOP);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_CHARIOTS_WORKSHOP);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_PHYSICIAN);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_FESTIVAL_SQUARE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_SPHYNX);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TEMPLE_COMPLEX_ALTAR);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_TEMPLE_COMPLEX_ORACLE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_SUN_TEMPLE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_GRANITE_QUARRY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_COPPER_MINE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_SANDSTONE_QUARRY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MAUSOLEUM);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_HENNA_FARM);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_ALEXANDRIA_LIBRARY);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_ZOO);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_CAESAREUM);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_PHAROS_LIGHTHOUSE);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_SMALL_ROYAL_TOMB);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_ABU_SIMBEL);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_ARTISANS_GUILD);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_LAMP_WORKSHOP);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_PAINT_WORKSHOP);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_MEDIUM_ROYAL_TOMB);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_LARGE_ROYAL_TOMB);
   REGISTER_GLOBAL_CONSTANT(J, BUILDING_GRAND_ROYAL_TOMB);
}

void js_register_city_overlays(js_State *J) {
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_NONE);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_WATER);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_RELIGION);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_FIRE);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_DAMAGE);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_CRIME);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_ENTERTAINMENT);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_BOOTH);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_BANDSTAND);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_PAVILION);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_HIPPODROME);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_EDUCATION);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_SCRIBAL_SCHOOL);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_LIBRARY);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_ACADEMY);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_APOTHECARY);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_DENTIST);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_PHYSICIAN);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_MORTUARY);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_TAX_INCOME);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_FOOD_STOCKS);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_DESIRABILITY);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_WORKERS_UNUSED);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_NATIVE);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_PROBLEMS);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_RELIGION_OSIRIS);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_RELIGION_RA);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_RELIGION_PTAH);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_RELIGION_SETH);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_RELIGION_BAST);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_FERTILITY);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_BAZAAR_ACCESS);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_ROUTING);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_HEALTH);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_LABOR);
   REGISTER_GLOBAL_CONSTANT(J, OVERLAY_COUTHOUSE);
}