#include "game_environment.h"

#include "core/log.h"

#include <cassert>

int GAME_ENV = ENGINE_ENV_MAX;
const char* game_name;
const char* pref_filename;

void init_game_environment(int env) {
    assert(env != ENGINE_ENV_MAX);
    GAME_ENV = env;
    game_name = "Akhenaten";
    pref_filename = "data_dir_pharaoh.txt";
    logs::info("Engine set to %s", game_name);
}

void assert_env_init() {
    assert(GAME_ENV < ENGINE_ENV_MAX);
}

const char* get_game_title() {
    assert_env_init();
    return game_name;
}
const char* get_engine_pref_path() {
    assert_env_init();
    return pref_filename;
}
