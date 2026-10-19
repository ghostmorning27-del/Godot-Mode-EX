#include "smart_camera_switcher.h"
void SmartCameraSwitcher::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_fps_camera", "camera"), &SmartCameraSwitcher::set_fps_camera);
    ClassDB::bind_method(D_METHOD("get_fps_camera"), &SmartCameraSwitcher::get_fps_camera);
    ClassDB::bind_method(D_METHOD("set_tps_camera", "camera"), &SmartCameraSwitcher::set_tps_camera);
    ClassDB::bind_method(D_METHOD("get_tps_camera"), &SmartCameraSwitcher::get_tps_camera);
    ClassDB::bind_method(D_METHOD("toggle_camera"), &SmartCameraSwitcher::toggle_camera);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "fps_camera", PROPERTY_HINT_NODE_TYPE, "Camera3D"), "set_fps_camera", "get_fps_camera");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "tps_camera", PROPERTY_HINT_NODE_TYPE, "Camera3D"), "set_tps_camera", "get_tps_camera");
}
void SmartCameraSwitcher::set_fps_camera(Camera3D *p_camera) { fps_camera = p_camera; }
Camera3D *SmartCameraSwitcher::get_fps_camera() const { return fps_camera; }
void SmartCameraSwitcher::set_tps_camera(Camera3D *p_camera) { tps_camera = p_camera; }
Camera3D *SmartCameraSwitcher::get_tps_camera() const { return tps_camera; }
void SmartCameraSwitcher::toggle_camera() {
    if (!fps_camera || !tps_camera) return;
    is_fps = !is_fps;
    if (is_fps) { tps_camera->set_current(false); fps_camera->set_current(true); } 
    else { fps_camera->set_current(false); tps_camera->set_current(true); }
}
SmartCameraSwitcher::SmartCameraSwitcher() { is_fps = true; }
