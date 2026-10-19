#ifndef RADIAL_MENU_H
#define RADIAL_MENU_H
#include "scene/gui/control.h"

class RadialMenu : public Control {
    GDCLASS(RadialMenu, Control);
private:
    bool is_open = false;
protected:
    static void _bind_methods();
public:
    void toggle_menu();
    bool get_is_open() const;
    RadialMenu();
};
#endif
