#include "ui.h"

#include "button.h"
#include "generic_button.h"
#include "arrow_button.h"
#include "image_button.h"
#include "lang_text.h"
#include "panel.h"
#include "game/game.h"
#include "graphics/boilerplate.h"

#include <stack>

namespace ui {
    struct state {
        std::stack<vec2i> _offset;
        std::vector<generic_button> buttons;
        std::vector<image_button> img_buttons;
        std::vector<arrow_button> arw_buttons;

        inline const vec2i offset() { return _offset.empty() ? vec2i{0, 0} : _offset.top(); }
    };

    state g_state;
    generic_button dummy;
}

void ui::begin_widget(vec2i offset, bool relative) {
    if (relative) {
        vec2i top = g_state._offset.empty() ? vec2i{0, 0} : g_state._offset.top();
        offset += top;
    }
    g_state._offset.push(offset);
}

void ui::begin_frame() {
    g_state._offset = {};
    g_state.buttons.clear();
    g_state.img_buttons.clear();
    g_state.arw_buttons.clear();
}

void ui::end_widget() {
    if (!g_state._offset.empty()) {
        g_state._offset.pop();
    }
}

bool ui::handle_mouse(const mouse *m) {
    bool handle = false;
    int tmp_btn = 0;
    handle |= !!generic_buttons_handle_mouse(m, g_state.offset(), g_state.buttons, tmp_btn);
    handle |= !!image_buttons_handle_mouse(m, g_state.offset(), g_state.img_buttons, tmp_btn);
    handle |= !!arrow_buttons_handle_mouse(m, g_state.offset(), g_state.arw_buttons, tmp_btn);

    return handle;
}

int ui::button_hover(const mouse *m) {
    for (auto &btn : g_state.buttons) {
        if (is_button_hover(btn, g_state.offset())) {
            return (std::distance(&g_state.buttons.front(), &btn) + 1);
        }
    }

    return 0;
}

generic_button &ui::button(pcstr label, vec2i pos, vec2i size) {
    const vec2i offset = g_state.offset();

    g_state.buttons.push_back({pos.x, pos.y, size.x + 4, size.y + 4, button_none, button_none, 0, 0});
    int focused = is_button_hover(g_state.buttons.back(), offset);

    button_border_draw(offset.x + pos.x, offset.y + pos.y, size.x, size.y, focused ? 1 : 0);
    text_draw_centered((uint8_t *)label, offset.x + pos.x + 1, offset.y + pos.y + 4, 20, FONT_NORMAL_BLACK_ON_LIGHT, 0);

    return g_state.buttons.back();
}

generic_button &ui::button(uint32_t id) {
    return (id < g_state.buttons.size()) ? g_state.buttons[id] : dummy;
}

image_button &ui::img_button(uint32_t group, uint32_t id, vec2i pos, vec2i size, int offset) {
    const vec2i img_offset = g_state.offset();
    const mouse *m = mouse_get();

    g_state.img_buttons.push_back({pos.x, pos.y, size.x + 4, size.y + 4, IB_NORMAL, group, id, offset, button_none, button_none, 0, 0, true});
    auto &button = g_state.img_buttons.back();
    button.focused = is_button_hover(g_state.img_buttons.back(), img_offset);
    button.pressed = button.focused && m->left.is_down;
    image_buttons_draw(img_offset, button);

    return g_state.img_buttons.back();
}

int ui::label(int group, int number, vec2i pos, font_t font, UiFlags_ flags, int box_width) {
    const vec2i offset = g_state.offset();
    if (!!(flags & UiFlags_LabelCentered)) {
        lang_text_draw_centered(group, number, offset.x + pos.x, offset.y + pos.y, box_width, font);
        return box_width;
    } else {
        return lang_text_draw(group, number, offset + pos, font);
    }
}

int ui::label_num(int group, int number, int amount, vec2i pos, font_t font, pcstr postfix) {
    const vec2i offset = g_state.offset();
    return lang_text_draw_amount(group, number, amount, offset.x + pos.x, offset.y + pos.y, font, postfix);
}

int ui::label_percent(int amount, vec2i pos, font_t font) {
    const vec2i offset = g_state.offset();
    return text_draw_percentage(amount, offset.x + pos.x, offset.y + pos.y, font);
}

void ui::panel(vec2i pos, vec2i size, UiFlags_ flags) {
    const vec2i offset = g_state.offset();
    if (!!(flags & UiFlags_PanelOuter)) {
        outer_panel_draw(offset + pos, size.x, size.y);
    }
}

void ui::icon(vec2i pos, e_resource img) {
    const vec2i offset = g_state.offset();
    painter ctx = game.painter();
    ImageDraw::img_generic(ctx, image_id_resource_icon(RESOURCE_DEBEN), offset.x + pos.x, offset.y + pos.y);
}

arrow_button &ui::arw_button(vec2i pos, bool up, bool tiny) {
    const vec2i offset = g_state.offset();

    g_state.arw_buttons.push_back({pos.x, pos.y, up ? 17 : 15, 24, button_none, 0, 0});
    arrow_buttons_draw(offset, g_state.arw_buttons.back(), tiny);

    return g_state.arw_buttons.back();
}