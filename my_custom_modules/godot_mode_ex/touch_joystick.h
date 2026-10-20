#ifndef TOUCH_JOYSTICK_H
#define TOUCH_JOYSTICK_H
#include "scene/gui/control.h"

class TouchJoystick : public Control {
    GDCLASS(TouchJoystick, Control);
private:
    Vector2 output = Vector2(0, 0);
    bool is_pressed = false;
    float radius = 100.0f;
protected:
    static void _bind_methods();
    void _gui_input(const Ref<InputEvent> &p_event) override;
public:
    Vector2 get_output() const;
    void set_radius(float p_radius);
    TouchJoystick();
};
#endif
