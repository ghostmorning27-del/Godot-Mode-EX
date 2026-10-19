#include "smart_character.h"

void SmartCharacter::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_anim_player", "anim"), &SmartCharacter::set_anim_player);
    ClassDB::bind_method(D_METHOD("get_anim_player"), &SmartCharacter::get_anim_player);
    ClassDB::bind_method(D_METHOD("set_character_mesh", "mesh"), &SmartCharacter::set_character_mesh);
    ClassDB::bind_method(D_METHOD("get_character_mesh"), &SmartCharacter::get_character_mesh);

    ClassDB::bind_method(D_METHOD("play_run"), &SmartCharacter::play_run);
    ClassDB::bind_method(D_METHOD("play_jump"), &SmartCharacter::play_jump);
    ClassDB::bind_method(D_METHOD("play_idle"), &SmartCharacter::play_idle);
    ClassDB::bind_method(D_METHOD("play_crouch"), &SmartCharacter::play_crouch);
    ClassDB::bind_method(D_METHOD("toggle_camera_view"), &SmartCharacter::toggle_camera_view);

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "anim_player", PROPERTY_HINT_NODE_TYPE, "AnimationPlayer"), "set_anim_player", "get_anim_player");
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "character_mesh", PROPERTY_HINT_NODE_TYPE, "Node3D"), "set_character_mesh", "get_character_mesh");
}

void SmartCharacter::set_anim_player(AnimationPlayer *p_anim) { anim_player = p_anim; }
AnimationPlayer *SmartCharacter::get_anim_player() const { return anim_player; }
void SmartCharacter::set_character_mesh(Node3D *p_mesh) { character_mesh = p_mesh; }
Node3D *SmartCharacter::get_character_mesh() const { return character_mesh; }

void SmartCharacter::play_run() { if (anim_player && anim_player->has_animation("run")) anim_player->play("run"); }
void SmartCharacter::play_jump() { if (anim_player && anim_player->has_animation("jump")) anim_player->play("jump"); }
void SmartCharacter::play_idle() { if (anim_player && anim_player->has_animation("idle")) anim_player->play("idle"); }
void SmartCharacter::play_crouch() { if (anim_player && anim_player->has_animation("crouch")) anim_player->play("crouch"); }

void SmartCharacter::toggle_camera_view() {
    if (fps_camera && tps_camera) {
        bool is_fps = fps_camera->is_current();
        fps_camera->set_current(!is_fps);
        tps_camera->set_current(is_fps);
    }
}

SmartCharacter::SmartCharacter() {}
