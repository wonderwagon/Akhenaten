log_info("akhenaten: images started")

images = [
	// spr main
	{img: ANIM_EMIGRANT_WALK, pack: PACK_SPR_MAIN, id: 2}, // 65
	{img: ANIM_EMIGRANT_DEATH, pack: PACK_SPR_MAIN, id: 3}, // 161
	{img: ANIM_ARCHITECT_WALK, pack:PACK_SPR_MAIN, id:4},  //  169
	{img: ANIM_ARCHITECT_DEATH, pack:PACK_SPR_MAIN, id:5}, // 265
	{img: IMG_FIREMAN, pack:PACK_SPR_MAIN, id:6},  // 273
	{img: IMG_FIREMAN_DEATH, pack:PACK_SPR_MAIN, id:7},  // 273
  {img: IMG_FIREMAN_FIGHT_FIRE, pack:PACK_SPR_MAIN, id:8, offset:0},
	{img: IMG_HOMELESS, pack: PACK_SPR_MAIN, id: 12}, // 782
	{img: IMG_HOMELESS_DEATH, pack: PACK_SPR_MAIN, id: 13}, // 782
	{img: IMG_IMMIGRANT, pack: PACK_SPR_MAIN, id: 14},// 886
	{img: IMG_IMMIGRANT_DEATH, pack: PACK_SPR_MAIN, id: 15},// 886
	{img: ANIM_TAX_COLLECTOR_WALK, pack:PACK_SPR_MAIN, id:41},
	{img: ANIM_TAX_COLLECTOR_DEATH, pack:PACK_SPR_MAIN, id:42},
	{img: ANIM_CARTPUSHER_WALK, pack: PACK_SPR_MAIN, id:43},
	{img: ANIM_CARTPUSHER_DEATH, pack: PACK_SPR_MAIN, id:44},
	{img: IMG_CARTPUSHER_CART, pack:PACK_SPR_MAIN, id:77},
	{img: IMG_SLED_BRICKS, pack:PACK_SPR_MAIN, id:89},
	{img: IMG_SLED_SANDSTONE_SMALL, pack:PACK_SPR_MAIN, id:101},
	{img: IMG_SLED_STONE_SMALL, pack:PACK_SPR_MAIN, id:102},
	{img: IMG_SLED_GRANITE_SMALL, pack:PACK_SPR_MAIN, id:103},
	{img: IMG_SLED_LIMESTONE_SMALL, pack:PACK_GENERAL, id:104},
	{img: IMG_CART_COPPER, pack:PACK_SPR_MAIN, id:107},
	{img: ANIM_JUGGLER_WALK, pack:PACK_SPR_MAIN, id:130},
	{img: ANIM_JUGGLER_DEATH, pack:PACK_SPR_MAIN, id:131},
	{img: IMG_FISHING_BOAT, pack:PACK_SPR_MAIN, id:133 }, 	// 7014
	{img: IMG_FISHING_BOAT_WORK, pack:PACK_SPR_MAIN, id:135 }, // 7046
	{img: IMG_FISHING_BOAT_DEATH, pack:PACK_SPR_MAIN, id:136 }, // 7118
	{img: IMG_FISHING_BOAT_IDLE, pack:PACK_SPR_MAIN, id:137 }, // 7129
	{img: ANIM_OSTRICH_WALK, pack:PACK_SPR_MAIN, id:156}, // 7823 - 0
	{img: ANIM_OSTRICH_DEATH, pack:PACK_SPR_MAIN, id:158}, // 7823 - 0
	{img: ANIM_OSTRICH_EATING, pack:PACK_SPR_MAIN, id:159, offset:0},
	{img: ANIM_OSTRICH_IDLE, pack:PACK_SPR_MAIN, id:160, offset:0},
	{img: ANIM_MUSICIAN_WALK, pack:PACK_SPR_MAIN, id:191},
	{img: IMG_SCRIBER_WALK, pack:PACK_SPR_MAIN, id:199},
	{img: IMG_SCRIBER_DEATH, pack:PACK_SPR_MAIN, id:200},
	{img: IMG_TEACHER_WALK, pack:PACK_SPR_MAIN, id:201},
	{img: IMG_TEACHER_DEATH, pack:PACK_SPR_MAIN, id:202},
	{img: ANIM_LABOR_SEEKER_WALK, pack:PACK_SPR_MAIN, id:206},       // 9909
	{img: ANIM_LABOR_SEEKER_DEATH, pack:PACK_SPR_MAIN, id:207}, // 10005
	{img: ANIM_DOCKER_WALK, pack:PACK_SPR_MAIN, id:43}, // 10005
	{img: ANIM_OSTRICH_HUNTER_WALK, pack:PACK_SPR_MAIN, id:45}, // 2657
	{img: ANIM_OSTRICH_HUNTER_DEATH, pack:PACK_SPR_MAIN, id:46}, // 2657
	{img: ANIM_OSTRICH_HUNTER_HUNT, pack:PACK_SPR_MAIN, id:47}, // 2753
	{img: ANIM_OSTRICH_HUNTER_FIGHT, pack:PACK_SPR_MAIN, id:48}, // 2761
	{img: ANIM_OSTRICH_HUNTER_UNPACK, pack:PACK_SPR_MAIN, id:49}, // 2857
	{img: ANIM_OSTRICH_HUNTER_PACK, pack:PACK_SPR_MAIN, id:50}, // 3049
	{img: ANIM_OSTRICH_HUNTER_MOVE_PACK, pack:PACK_SPR_MAIN, id:51}, // 3193

	// spr ambient
	{img: IMG_FLOTSAM, pack:PACK_SPR_AMBIENT, id:0},  // 1 + 15831
	{img: IMG_FISHING_POINT, pack:PACK_SPR_AMBIENT, id:8},
	{img: IMG_EXPLOSION, pack:PACK_SPR_AMBIENT, id:12, offset:0},
	{img: IMG_FISHING_POINT_BUBLES, pack:PACK_SPR_AMBIENT, id:11},
	{img: IMG_FISHIHG_WHARF_ANIM, pack: PACK_SPR_AMBIENT, id:47},  // 2551 + 15831
	{img: ANIM_GOLD_MINE, pack:PACK_SPR_AMBIENT, id:48},
	{img: ANIM_SANDSTONE_QUARRY_1, pack:PACK_SPR_AMBIENT, id:49},
	{img: ANIM_SANDSTONE_QUARRY_2, pack:PACK_SPR_AMBIENT, id:49},

	// spr terrain
	{img: IMG_BUILDING_DOCK, pack:PACK_TERRAIN, id:49},

	// spr general
	{img: IMG_CONSERVATORY, pack:PACK_GENERAL, id:51},
	{img: IMG_BRICKLAYERS_GUILD, pack:PACK_GENERAL, id:57},
	{img: IMG_BANDSTAND_SQUARE, pack:PACK_GENERAL, id:58},
	{img: IMG_WATER_SUPPLY, pack:PACK_GENERAL, id:69, offset:0},
	{img: IMG_WATER_SUPPLY_FANCY, pack:PACK_GENERAL, id:69, offset:2},
	{img: IMG_PHYSICIAN, pack:PACK_GENERAL, id:70},
	{img: IMG_GUILD_STONEMASONS, pack:PACK_GENERAL, id:88},
	{img: IMG_BANDSTAND_SN_S, pack:PACK_GENERAL, id:92},
	{img: IMG_BANDSTAND_SN_N, pack:PACK_GENERAL, id:92, offset:1},
	{img: IMG_BANDSTAND_WE_W, pack:PACK_GENERAL, id:92, offset:2},
	{img: IMG_BANDSTAND_WE_E, pack:PACK_GENERAL, id:92, offset:3},
	{img: IMG_GRANARY, pack:PACK_GENERAL, id:99},
	{img: IMG_BOOTH_SQUARE, pack:PACK_GENERAL, id:112},
	{img: IMG_BOOTH, pack:PACK_GENERAL, id:114},
	{img: IMG_GRANARY_RESOURCES, pack:PACK_GENERAL, id:99, offset:2},
	{img: IMG_CATTLE_RANCH, pack:PACK_GENERAL, id:105},
	{img: IMG_GOLD_MINE, pack:PACK_GENERAL, id:185},
	{img: IMG_PLAINSTONE_QUARRY, pack:PACK_GENERAL, id:187},
	{img: IMG_COPPER_MINE, pack:PACK_GENERAL, id:196},
	{img: IMG_SANDSTONE_QUARRY, pack:PACK_GENERAL, id:197},

	// icon resources
	{img: IMG_BRICKS_WORKSHOP, pack:PACK_GENERAL, id:124},
	{img: IMG_RESOURCE_ICONS, pack:PACK_GENERAL, id:129},
	{img: IMG_RESOURCE_GAMEMEAT, pack:PACK_GENERAL, id:205},
	{img: IMG_RESOURCE_STRAW, pack:PACK_GENERAL, id:206},
	{img: IMG_RESOURCE_CLAY, pack:PACK_GENERAL, id:207},

	//{img: IMG_EMIGRANT, pack: PACK_SPR_MAIN, id: 13}, // 878
	//{img: IMG_FISHING_BOAT ???, pack:PACK_SPR_MAIN, id:133 }, 	// 7014
	{img: ANIM_MUSICIAN_DEATH, pack:PACK_SPR_MAIN, id:192},
	{img: IMG_JUGGLER_SHOW, pack:PACK_SPR_AMBIENT, id:7, offset:-1},
	{img: IMG_MUSICIAN_SHOW_SN, pack:PACK_SPR_AMBIENT, id:10, offset:-1},
	{img: IMG_MUSICIAN_SHOW_WE, pack:PACK_SPR_AMBIENT, id:9, offset:-1},
	{img: IMG_CART_BARLEY, pack:PACK_SPR_MAIN, id:91},
	{img: IMG_SIDE_PANEL, pack:PACK_GENERAL, id:121, offset:0},
	{img: IMG_TOP_MENU_BACKGROUND, pack:PACK_GENERAL, id:121, offset:8},
	{img: IMG_EDITOR_SIDE_PANEL, pack:PACK_GENERAL, id:121, offset:0},
	{img: IMG_RESOURCE_PAPYRUS, pack:PACK_GENERAL, id:207, offset:0},
	{img: IMG_EMPIRE_ROUTE_HL_CLOSED, pack:PACK_GENERAL, id:149, offset:211},
	{img: IMG_EMPIRE_ROUTE_OPEN, pack:PACK_GENERAL, id:149, offset:201},
	{img: IMG_EMPIRE_ROUTE_HL_OPEN, pack:PACK_GENERAL, id:149, offset:186},
	{img: IMG_MINIMAP_BLACK, pack:PACK_GENERAL, id:149, offset:5},
	{img: IMG_MINIMAP_BRIGHT_TEAL, pack:PACK_GENERAL, id:149, offset:170},
	{img: IMG_MINIMAP_DARK_GREY, pack:PACK_GENERAL, id:149, offset:210},
	{img: IMG_MINIMAP_GREEN, pack:PACK_GENERAL, id:149, offset:160},
	{img: IMG_MINIMAP_DARK_RED, pack:PACK_GENERAL, id:149, offset:165},
	{img: IMG_MINIMAP_PURPLE, pack:PACK_GENERAL, id:149, offset:175},
	{img: IMG_MINIMAP_LIGHT_YELLOW, pack:PACK_GENERAL, id:149, offset:180},
	{img: IMG_MINIMAP_LILAC, pack:PACK_GENERAL, id:149, offset:195},
	{img: IMG_MINIMAP_SPENT_TEAL, pack:PACK_GENERAL, id:149, offset:200},
	{img: IMG_MINIMAP_COLOR, pack:PACK_GENERAL, id:149, offset:0},
	{img: IMG_TRADE_AMOUNT, pack:PACK_GENERAL, id:171, offset:0},
	{img: IMG_TRADER_CARAVAN, pack:PACK_SPR_AMBIENT, id:20, offset:0},
	{img: IMG_TRADER_CARAVAN_DEATH, pack:PACK_SPR_AMBIENT, id:21, offset:0},
	{img: IMG_TRADER_CARAVAN_DONKEY, pack:PACK_SPR_MAIN, id:52, offset:0},
	{img: IMG_TRADER_CARAVAN_DONKEY_DEATH, pack:PACK_SPR_MAIN, id:53, offset:0},
	{img: IMG_HOUSE_HUT, pack:PACK_GENERAL, id:26, offset:0},
	{img: IMG_HOUSE_SHANTY, pack:PACK_GENERAL, id:27, offset:0},
	{img: IMG_HOUSE_COTTAGE, pack:PACK_GENERAL, id:28, offset:0},
	{img: IMG_HOUSE_HOMESTEAD, pack:PACK_GENERAL, id:29, offset:0},
	{img: IMG_HOUSE_APARTMENT, pack:PACK_GENERAL, id:30, offset:0},
	{img: IMG_POTTERY_WORKSHOP, pack:PACK_GENERAL, id:125, offset:0},
	{img: ANIM_BREWERY_WORKSHOP, pack:PACK_GENERAL, id:116, offset:0},
	{img: IMG_SMALL_MASTABA, pack:PACK_MASTABA, id:2, offset:7},
	{img: IMG_BAZAAR, pack:PACK_GENERAL, id:22, offset:0},
	{img: IMG_BAZAAR_FANCY, pack:PACK_GENERAL, id:22, offset:13},
	{img: IMG_BRICKLAYER_WALK, pack:PACK_SPR_MAIN, id:109},
	{img: IMG_BRICKLAYER_DEATH, pack:PACK_SPR_MAIN, id:110},
	{img: IMG_BRICKLAYER_WORK, pack:PACK_SPR_MAIN, id:111},
	{img: IMG_BRICKLAYER_IDLE, pack:PACK_SPR_MAIN, id:112},
	{img: IMG_WORKER_AKNH, pack:PACK_SPR_MAIN, id:116},
	{img: IMG_WORKER_AKNH_WORK, pack:PACK_SPR_MAIN, id:118},
	{img: IMG_WORKER_AKNH_TILING, pack:PACK_SPR_MAIN, id:118},
	{img: IMG_WORKER_AKNH_SEEDING, pack:PACK_SPR_MAIN, id:119},
	{img: IMG_WORKER_AKNH_HARVESTING, pack:PACK_SPR_MAIN, id:120},
	{img: IMG_MONUMENT_ENTER, pack:PACK_GENERAL, id:114},
	{img: IMG_SLED_PULLER, pack:PACK_SPR_MAIN, id:121},
	{img: IMG_BIGSLED_EMPTY, pack:PACK_SPR_MAIN, id:166},
	{img: IMG_BIGSLED_STONE, pack:PACK_SPR_MAIN, id:167},
	{img: IMG_BIGSLED_SANDSTONE, pack:PACK_SPR_MAIN, id:168},
	{img: IMG_BIGSLED_GRANITE, pack:PACK_SPR_MAIN, id:169},
	{img: IMG_BIGSLED_LIMESTONE, pack:PACK_SPR_MAIN, id:170},
	{img: IMG_BIGSLED_CLAY, pack:PACK_SPR_MAIN, id:171},
	{img: IMG_BIGSLED_BRICKS, pack:PACK_SPR_MAIN, id:172},
	{img: IMG_SMALL_MASTABA_BRICKS, pack:PACK_MASTABA, id:1, offset:0},
	{img: IMG_BUILDING_FIREHOUSE, pack:PACK_GENERAL, id:78},
	{img: IMG_BUILDING_APOTHECARY, pack:PACK_GENERAL, id:68},
	{img: IMG_PERSONAL_MANSION, pack:PACK_GENERAL, id:85},
	{img: IMG_ADVISOR_ICONS, pack:PACK_GENERAL, id:128, offset:0},
	{img: IMG_ADVISOR_BACKGROUND, pack:PACK_UNLOADED, id:2, offset:0},
	{img: IMG_VILLAGE_PALACE, pack:PACK_GENERAL, id:47, offset:0},
	{img: IMG_JUGGLER_SCHOOL, pack:PACK_GENERAL, id:46, offset:0},
	{img: IMG_CLAY_PIT, pack:PACK_GENERAL, id:40, offset:0},
	{img: IMG_GEMSTONE_MINE, pack:PACK_GENERAL, id:188, offset:0},
	{img: IMG_TEMPLE_OSIRIS, pack:PACK_GENERAL, id:25, offset:0},
	{img: IMG_TEMPLE_RA, pack:PACK_GENERAL, id:21, offset:0},
	{img: IMG_TEMPLE_PTAH, pack:PACK_GENERAL, id:20, offset:0},
	{img: IMG_TEMPLE_SETH, pack:PACK_GENERAL, id:19, offset:0},
	{img: IMG_TEMPLE_BAST, pack:PACK_GENERAL, id:76, offset:0},
	{img: IMG_WEAPONSMITH, pack:PACK_GENERAL, id:123, offset:0},
	{img: IMG_GRANARY_ANIM, pack:PACK_SPR_AMBIENT, id:47, offset:0},
	{img: IMG_WATER_CARRIER, pack:PACK_SPR_MAIN, id:59, offset:0},
	{img: IMG_WATER_CARRIER_DEATH, pack:PACK_SPR_MAIN, id:60, offset:0},
	{img: IMG_PRIEST_OSIRIS, pack:PACK_SPR_MAIN, id:197, offset:0},
	{img: IMG_PRIEST_OSIRIS_DEATH, pack:PACK_SPR_MAIN, id:198, offset:0},
	{img: IMG_PRIEST_RA, pack:PACK_SPR_MAIN, id:210, offset:0},
	{img: IMG_PRIEST_RA_DEATH, pack:PACK_SPR_MAIN, id:211, offset:0},
	{img: IMG_PRIEST_PTAH, pack:PACK_SPR_MAIN, id:187, offset:0},
	{img: IMG_PRIEST_PTAH_DEATH, pack:PACK_SPR_MAIN, id:188, offset:0},
	{img: IMG_PRIEST_SETH, pack:PACK_SPR_MAIN, id:193, offset:0},
	{img: IMG_PRIEST_SETH_DEATH, pack:PACK_SPR_MAIN, id:194, offset:0},
	{img: IMG_PRIEST_BAST, pack:PACK_SPR_MAIN, id:208, offset:0},
	{img: IMG_PRIEST_BAST_DEATH, pack:PACK_SPR_MAIN, id:209, offset:0},
	{img: IMG_TERRAIN_FLOODPLAIN, pack:PACK_TERRAIN, id:31, offset:0},
	{img: ANIM_FERRY_BOAT, pack:PACK_SPR_MAIN, id:138, offset:0},
	{img: ANIM_MARKET_BUYER_WALK, pack:PACK_SPR_MAIN, id:16, offset:0},
	{img: ANIM_MARKET_BUYER_DEATH, pack:PACK_SPR_MAIN, id:17, offset:0},
	{img: ANIM_MARKET_LADY_WALK, pack:PACK_SPR_MAIN, id:18, offset:0},
	{img: ANIM_MARKET_LADY_DEATH, pack:PACK_SPR_MAIN, id:19, offset:0},
	{img: ANIM_DELIVERY_BOY_WALK, pack:PACK_SPR_MAIN, id:9, offset:0},
	{img: ANIM_DELIVERY_BOY_DEATH, pack:PACK_SPR_MAIN, id:10, offset:0},
	{img: ANIM_TRADER_SHIP_WALK, pack:PACK_SPR_MAIN, id:40, offset:0},
	{img: ANIM_TRADER_SHIP_DEATH, pack:PACK_SPR_MAIN, id:41, offset:0},
	{img: ANIM_TRADER_SHIP_IDLE, pack:PACK_SPR_MAIN, id:42, offset:0},
	{img: ANIM_DOCTOR_WALK, pack:PACK_SPR_MAIN, id:71, offset:0},
	{img: ANIM_DOCTOR_DEATH, pack:PACK_SPR_MAIN, id:72, offset:0},
	{img: ANIM_HERBALIST_WALK, pack:PACK_SPR_MAIN, id:180, offset:0},
	{img: ANIM_HERBALIST_DEATH, pack:PACK_SPR_MAIN, id:181, offset:0},
	{img: ANIM_DANCER_WALK, pack:PACK_SPR_MAIN, id:128, offset:0},
	{img: ANIM_DANCER_DEATH, pack:PACK_SPR_MAIN, id:129, offset:0},
	{img: IMG_STORAGE_YARD, pack:PACK_GENERAL, id:82, offset:0},
	{img: ANIM_STORAGE_YARD_WORK, pack:PACK_SPR_AMBIENT, id:51, offset:0},
	{img: IMG_WORKCAMP, pack:PACK_GENERAL, id:77, offset:0},
	{img: IMG_BUILDING_REED_GATHERER, pack:PACK_GENERAL, id:24, offset:0},
	{img: ANIM_REED_GATHERER_WALK, pack:PACK_SPR_MAIN, id:37, offset:0},
	{img: ANIM_REED_GATHERER_DEATH, pack:PACK_SPR_MAIN, id:38, offset:0},
	{img: ANIM_REED_GATHERER_WORK, pack:PACK_SPR_MAIN, id:39, offset:0},
	{img: ANIM_REED_GATHERER_RETURN, pack:PACK_SPR_MAIN, id:40, offset:0},
]

cart_offsets = [
  {x:17, y:-7},
  {x:22, y:-1},
  {x:17, y:7},
  {x:0, 	y:11},
  {x:-17, y:6},
  {x:-22, y:-1},
  {x:-17, y:-7},
  {x:0, y:-12}
]

sled_offsets = [
  {x:-17, y:9},
  {x:22, y:-1},
  {x:-15, y:-5},
  {x:0, 	y:11},
  {x:12, y:-2},
  {x:-22, y:-1},
  {x:17, y:7},
  {x:0, y:-12}
]
