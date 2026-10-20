#include "register_types.h"
#include "core/object/class_db.h"
#include "touch_joystick.h"
#include "touch_button.h"

void initialize_godot_mode_ex_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) return;
    GDREGISTER_CLASS(TouchJoystick);
    GDREGISTER_CLASS(TouchButton);
}
void uninitialize_godot_mode_ex_module(ModuleInitializationLevel p_level) {}
