#include "radial_menu.h"

void RadialMenu::_bind_methods() {
    ClassDB::bind_method(D_METHOD("toggle_menu"), &RadialMenu::toggle_menu);
    ClassDB::bind_method(D_METHOD("get_is_open"), &RadialMenu::get_is_open);
}

void RadialMenu::toggle_menu() {
    is_open = !is_open;
    set_visible(is_open);
}

bool RadialMenu::get_is_open() const {
    return is_open;
}

RadialMenu::RadialMenu() {
    set_anchors_preset(Control::PRESET_CENTER);
    set_custom_minimum_size(Vector2(200, 200));
    set_visible(false);
}
