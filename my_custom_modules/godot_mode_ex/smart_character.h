#ifndef SMART_CHARACTER_H
#define SMART_CHARACTER_H
#include "scene/3d/node_3d.h"
#include "scene/animation/animation_player.h"
#include "scene/3d/camera_3d.h"

class SmartCharacter : public Node3D {
    GDCLASS(SmartCharacter, Node3D);
private:
    AnimationPlayer *anim_player = nullptr;
    Node3D *character_mesh = nullptr;
    Camera3D *fps_camera = nullptr;
    Camera3D *tps_camera = nullptr;
protected:
    static void _bind_methods();
public:
    void set_anim_player(AnimationPlayer *p_anim);
    AnimationPlayer *get_anim_player() const;
    void set_character_mesh(Node3D *p_mesh);
    Node3D *get_character_mesh() const;
    
    void play_run();
    void play_jump();
    void play_idle();
    void play_crouch();
    void toggle_camera_view();

    SmartCharacter();
};
#endif
