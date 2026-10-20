#include "touch_joystick.h"
#include "core/input/input_event.h"

void TouchJoystick::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_output"), &TouchJoystick::get_output);
    ClassDB::bind_method(D_METHOD("set_radius", "radius"), &TouchJoystick::set_radius);
}

void TouchJoystick::_gui_input(const Ref<InputEvent> &p_event) {
    Ref<InputEventScreenTouch> touch = p_event;
    if (touch.is_valid()) {
        is_pressed = touch->is_pressed();
        if (is_pressed) { output = (touch->get_position() - get_size() / 2).normalized(); }
        else { output = Vector2(0, 0); }
    }
    Ref<InputEventScreenDrag> drag = p_event;
    if (drag.is_valid() && is_pressed) {
        output = (drag->get_position() - get_size() / 2).normalized();
    }
}

Vector2 TouchJoystick::get_output() const { return output; }
void TouchJoystick::set_radius(float p_radius) { radius = p_radius; set_custom_minimum_size(Vector2(radius*2, radius*2)); }
TouchJoystick::TouchJoystick() { set_custom_minimum_size(Vector2(radius*2, radius*2)); }
