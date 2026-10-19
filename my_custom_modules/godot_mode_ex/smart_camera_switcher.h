#ifndef SMART_CAMERA_SWITCHER_H
#define SMART_CAMERA_SWITCHER_H
#include "scene/3d/camera_3d.h"
#include "scene/3d/node_3d.h"
class SmartCameraSwitcher : public Node3D {
    GDCLASS(SmartCameraSwitcher, Node3D);
private:
    Camera3D *fps_camera;
    Camera3D *tps_camera;
    bool is_fps = true;
protected:
    static void _bind_methods();
public:
    void set_fps_camera(Camera3D *p_camera);
    Camera3D *get_fps_camera() const;
    void set_tps_camera(Camera3D *p_camera);
    Camera3D *get_tps_camera() const;
    void toggle_camera();
    SmartCameraSwitcher();
};
#endif
