#ifndef TOUCH_BUTTON_H
#define TOUCH_BUTTON_H
#include "scene/gui/button.h"

class TouchButton : public Button {
    GDCLASS(TouchButton, Button);
private:
    float min_size = 64.0f; // حجم الزر المناسب للهاتف
protected:
    static void _bind_methods();
public:
    void set_min_size_px(float p_size);
    float get_min_size_px() const;
    TouchButton();
};
#endif
