#include "register_types.h"
#include "core/object/class_db.h"
#include "touch_button.h"
#include "smart_camera_switcher.h"
#include "mobile_sensors.h"

void initialize_godot_mode_ex_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) return;
    GDREGISTER_CLASS(TouchButton);
    GDREGISTER_CLASS(SmartCameraSwitcher);
    GDREGISTER_CLASS(MobileSensors);
}
void uninitialize_godot_mode_ex_module(ModuleInitializationLevel p_level) {}
