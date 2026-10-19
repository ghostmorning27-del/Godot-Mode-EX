#include "touch_button.h"
void TouchButton::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_min_size_px", "size"), &TouchButton::set_min_size_px);
    ClassDB::bind_method(D_METHOD("get_min_size_px"), &TouchButton::get_min_size_px);
}
void TouchButton::set_min_size_px(float p_size) { min_size = p_size; set_custom_minimum_size(Size2(min_size, min_size)); }
float TouchButton::get_min_size_px() const { return min_size; }
TouchButton::TouchButton() { set_custom_minimum_size(Size2(min_size, min_size)); }
