#include "figure_musician.h"

#include "figure/service.h"
#include "city/city_health.h"
#include "city/sentiment.h"
#include "city/labor.h"
#include "city/ratings.h"
#include "city/houses.h"
#include "city/city.h"

#include "js/js_game.h"

figures::model_t<figure_musician> musician_m;

void figure_musician::update_shows() {
    building* b = destination();
    b->data.entertainment.days2 = 32;
}

svector<e_building_type, 4> figure_musician::allow_venue_types() const {
    return {BUILDING_BANDSTAND, BUILDING_PAVILLION};
}

sound_key figure_musician::phrase_key() const {
    svector<sound_key, 10> keys;
    uint32_t months_since_last_festival = g_city.religion.months_since_last_festival();
    if (months_since_last_festival < 6) {
        keys.push_back("i_like_festivals");
    }

    if (formation_get_num_forts() < 1) {
        keys.push_back("city_not_safety_workers_leaving");
    }

    if (g_city.health.value < 40) {
        keys.push_back("city_heath_too_low");
    }

    if (city_sentiment_low_mood_cause() == LOW_MOOD_NO_FOOD) {
        keys.push_back("no_food_in_city");
    }

    if (g_city.labor.workers_needed >= 10) {
        keys.push_back("need_workers");
    }

    if (g_city.religion.least_mood() <= GOD_MOOD_INDIFIRENT) { // any gods in wrath
        keys.push_back("gods_are_angry");
    } else {
        keys.push_back("gods_are_pleasures");
    }

    if (city_sentiment() < 30) {
        keys.push_back("city_is_bad_reputation");
    }

    if (city_sentiment_low_mood_cause() == LOW_MOOD_NO_JOBS) {
        keys.push_back("much_unemployments");
    }

    const house_demands &demands = g_city.houses;
    if (demands.missing.more_entertainment == 0) {
        keys.push_back("no_entertainment_need");
    }

    if (city_sentiment() < 50) {
        keys.push_back("city_not_bad");
    } else {
        keys.push_back("city_is_good");
    }

    int index = rand() % keys.size();
    return keys[index];
}

int figure_musician::provide_service() {
    int houses_serviced = 0;
    building *b = current_destination();
    if (b->type == BUILDING_BANDSTAND) {
        houses_serviced = provide_entertainment(b->data.entertainment.days2 ? 2 : 1, bandstand_coverage);
    } else if (b->type == BUILDING_PAVILLION) {
        houses_serviced = provide_entertainment(b->data.entertainment.days1 ? 2 : 1, senet_coverage);
    }

    return houses_serviced;
}

figure_sound_t figure_musician::get_sound_reaction(xstring key) const {
    return musician_m.sounds[key];
}

const animations_t &figure_musician::anim() const {
    return musician_m.anim;
}
