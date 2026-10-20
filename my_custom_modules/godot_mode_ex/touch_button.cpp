#include "touch_button.h"

void TouchButton::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_min_size_px", "size"), &TouchButton::set_min_size_px);
    ClassDB::bind_method(D_METHOD("get_min_size_px"), &TouchButton::get_min_size_px);
}
void TouchButton::set_min_size_px(float p_size) { min_size_px = p_size; set_custom_minimum_size(Vector2(min_size_px, min_size_px)); }
float TouchButton::get_min_size_px() const { return min_size_px; }
TouchButton::TouchButton() { set_custom_minimum_size(Vector2(min_size_px, min_size_px)); }
