#include "advisors.h"

#include "scenario/scenario.h"
#include "city/constants.h"
#include "city/coverage.h"
#include "city/finance.h"
#include "city/city.h"
#include "city/labor.h"
#include "city/migration.h"
#include "city/ratings.h"
#include "city/city_resource.h"
#include "city/warning.h"
#include "figure/formation.h"
#include "game/settings.h"
#include "game/tutorial.h"
#include "graphics/graphics.h"
#include "graphics/image.h"
#include "graphics/view/view.h"
#include "graphics/elements/generic_button.h"
#include "graphics/elements/image_button.h"
#include "graphics/image_groups.h"
#include "graphics/window.h"
#include "input/input.h"
#include "window/advisor/advisor_chief.h"
#include "window/advisor/advisor_education.h"
#include "window/advisor/advisor_entertainment.h"
#include "window/advisor/advisor_financial.h"
#include "window/advisor/advisor_health.h"
#include "window/advisor/housing.h"
#include "window/advisor/advisor_imperial.h"
#include "window/advisor/advisor_labor.h"
#include "window/advisor/advisor_military.h"
#include "window/advisor/monuments.h"
#include "window/advisor/advisor_population.h"
#include "window/advisor/advisor_ratings.h"
#include "window/advisor/advisor_religion.h"
#include "window/advisor/advisor_trade.h"
#include "window/window_city.h"
#include "window/message_dialog.h"
#include "game/game.h"
#include "js/js_game.h"

static const int ADVISOR_TO_MESSAGE_TEXT[] = {
  MESSAGE_DIALOG_ABOUT,
  MESSAGE_DIALOG_ADVISOR_LABOR,
  MESSAGE_DIALOG_ADVISOR_MILITARY,
  MESSAGE_DIALOG_ADVISOR_IMPERIAL,
  MESSAGE_DIALOG_ADVISOR_RATINGS,
  MESSAGE_DIALOG_ADVISOR_TRADE,
  MESSAGE_DIALOG_ADVISOR_POPULATION,
  MESSAGE_DIALOG_ADVISOR_HEALTH,
  MESSAGE_DIALOG_ADVISOR_EDUCATION,
  MESSAGE_DIALOG_ADVISOR_ENTERTAINMENT,
  MESSAGE_DIALOG_ADVISOR_RELIGION,
  MESSAGE_DIALOG_ADVISOR_FINANCIAL,
  MESSAGE_DIALOG_ADVISOR_CHIEF,
  MESSAGE_DIALOG_ABOUT,
  MESSAGE_DIALOG_ABOUT,
  MESSAGE_DIALOG_ABOUT,
  MESSAGE_DIALOG_ABOUT,
  MESSAGE_DIALOG_ABOUT,
  MESSAGE_DIALOG_ABOUT,
  MESSAGE_DIALOG_ADVISOR_POPULATION,
};

struct labor_btn {
    pcstr id;
    e_advisor adv;
};

static const labor_btn btns[] = { {"labor_btn", ADVISOR_LABOR}, {"military_btn", ADVISOR_MILITARY}, {"imperial_btn", ADVISOR_IMPERIAL},
                                  {"ratings_btn", ADVISOR_RATINGS}, {"trade_btn", ADVISOR_TRADE}, {"population_btn", ADVISOR_POPULATION},
                                  {"health_btn", ADVISOR_HEALTH}, {"education_btn", ADVISOR_EDUCATION}, {"entertainment_btn", ADVISOR_ENTERTAINMENT},
                                  {"religion_btn", ADVISOR_RELIGION}, {"financial_btn", ADVISOR_FINANCIAL}, {"chief_btn", ADVISOR_CHIEF},
                                  {"monuments_btn", ADVISOR_MONUMENTS} };

struct window_advisors_t : public ui::widget {
    autoconfig_window *current_advisor_window = nullptr;
    int current_advisor = ADVISOR_NONE;
    int focus_button_id;
    int advisor_height;

    autoconfig_window * sub_advisors[20] = {
        nullptr,
        ui::advisor_labors_window::instance(),
        ui::advisor_military_window::instance(),
        ui::advisor_imperial_window::instance(),
        ui::advisor_ratings_window::instance(),
        ui::advisor_trade_window::instance(),
        ui::advisor_population_window::instance(),
        ui::advisor_health_window::instance(),
        ui::advisor_education_window::instance(),
        ui::advisor_entertainment_window::instance(),
        ui::advisor_religion_window::instance(),
        ui::advisor_financial_window::instance(),
        ui::advisor_chief_window::instance(),
        ui::advisor_monuments_window::instance(),
        // sub-advisors begin here
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        ui::advisor_housing_window::instance()
    };

    void init();
    void draw_background();
    void draw_foreground();
    void set_advisor(int advisor);
    void handle_input(const mouse *m, const hotkeys *h);
};

window_advisors_t g_window_advisors;

ANK_REGISTER_CONFIG_ITERATOR(config_load_advisors_window);
void config_load_advisors_window() {
    g_window_advisors.load("advisors_window");
}

static void set_advisor_window() {
    auto &data = g_window_advisors;
    if (data.sub_advisors[data.current_advisor]) {
        data.current_advisor_window = data.sub_advisors[data.current_advisor];
        data.current_advisor_window->pos = screen_dialog_offset();
        data.current_advisor_window->init();
    } else {
        data.current_advisor_window = nullptr;
    }
}

bool is_advisor_available(e_advisor advisor) {
    return (mission_advisor_availability(advisor, scenario_campaign_scenario_id() + 1) == AVAILABLE);
}

void window_advisors_t::set_advisor(int advisor) {
    current_advisor = advisor;
    g_settings.last_advisor = advisor;
    
    for (auto &btn : btns) {
        ui[btn.id].select(false);
    }

    ui["back_btn"].enabled = true; // set button active when coming back to menu

    set_advisor_window();
}

void window_advisors_t::init() {
    g_city.labor.allocate_workers();

    city_finance_estimate_taxes();
    city_finance_estimate_wages();
    city_finance_update_interest();
    city_finance_update_salary();
    city_finance_calculate_totals();

    g_city.migration_determine_reason();

    g_city.houses_calculate_culture_demands();
    g_city.avg_coverage.update();
    g_city.health.update();

    city_resource_calculate_food_stocks_and_supply_wheat();
    formation_calculate_figures();

    g_city.ratings_update_explanations();

    set_advisor_window();

    for (auto &btn: btns) {
        ui[btn.id].enabled = is_advisor_available(btn.adv);
    }

    ui["back_btn"].enabled = true;
}

void window_advisors_t::draw_background() {
    graphics_set_to_dialog();
    advisor_height = current_advisor_window->draw_background();
    graphics_reset_dialog();

    for (auto &btn : btns) {
        ui[btn.id].onclick([advisor = btn.adv] {
            g_window_advisors.set_advisor(advisor);
            window_invalidate();
        });
        ui[btn.id].tooltip({ 1, uint8_t(70 + btn.adv) });
    }

    ui["back_btn"].onclick([] {
        window_city_show();
    });
}

void window_advisors_t::draw_foreground() {
    ui.draw();

    current_advisor_window->ui_draw_foreground();

    graphics_set_to_dialog();
    current_advisor_window->draw_foreground();
    graphics_reset_dialog();
}

static void handle_hotkeys(const hotkeys* h) {
    auto &data = g_window_advisors;
    if (h->show_advisor) {
        if (data.current_advisor == h->show_advisor)
            window_city_show();
        else {
            window_advisors_show_advisor((e_advisor)h->show_advisor);
        }
    }
}

void window_advisors_t::handle_input(const mouse* m, const hotkeys* h) {
    handle_hotkeys(h);

    ui.begin_widget(pos);
    if (ui.handle_mouse(m)) {
        return;
    }
    ui.end_widget();

    const mouse* m_dialog = mouse_in_dialog(m);
    if (current_advisor_window->handle_mouse(m_dialog)) {
        return;
    }

    if (current_advisor_window->ui_handle_mouse(m)) {
        return;
    }

    if (input_go_back_requested(m, h)) {
        window_city_show();
        return;
    }
}

static void button_help(int param1, int param2) {
    auto &data = g_window_advisors;
    if (data.current_advisor > 0) {
        window_message_dialog_show(ADVISOR_TO_MESSAGE_TEXT[data.current_advisor], -1, 0);
    }
}

static void get_tooltip(tooltip_context* c) {
    auto &data = g_window_advisors;
    int text_id = data.current_advisor_window->get_tooltip_text();

    if (text_id) {
        c->text.id = text_id;
        c->type = TOOLTIP_BUTTON;
    }
}

int window_advisors_get_advisor(void) {
    auto &data = g_window_advisors;
    return data.current_advisor;
}

void window_advisors_show_checked() {
    e_availability avail = mission_advisor_availability(ADVISOR_LABOR, scenario_campaign_scenario_id() + 1);
    if (avail == AVAILABLE) {
        g_window_advisors.set_advisor(g_settings.last_advisor);
        window_advisors_show();
    } else {
        city_warning_show(avail == NOT_AVAILABLE ? WARNING_NOT_AVAILABLE : WARNING_NOT_AVAILABLE_YET);
    }
}

int window_advisors_show_advisor(e_advisor advisor) {
    e_availability avail = mission_advisor_availability(advisor, scenario_campaign_scenario_id() + 1);
    if (avail == NOT_AVAILABLE || avail == NOT_AVAILABLE_YET) {
        city_warning_show(avail == NOT_AVAILABLE ? WARNING_NOT_AVAILABLE : WARNING_NOT_AVAILABLE_YET);
        return 0;
    }
    g_window_advisors.set_advisor(advisor);
    window_advisors_show();
    return 1;
}

void window_advisors_show(void) {
    static window_type window = {
        WINDOW_ADVISORS,
        [] { g_window_advisors.draw_background(); },
        [] { g_window_advisors.draw_foreground(); },
        [] (const mouse *m, const hotkeys *h) { g_window_advisors.handle_input(m, h); },
        get_tooltip
    };

    g_window_advisors.init();
    window_show(&window);
}