extends CharacterBody3D
class_name SmartCharacterGD

@export var speed: float = 5.0
@export var jump_velocity: float = 4.5
@export var anim_player: AnimationPlayer

var gravity: float = ProjectSettings.get_setting("physics/3d/default_gravity")

func _physics_process(delta: float) -> void:
    # الجاذبية
    if not is_on_floor():
        velocity.y -= gravity * delta

    # القفز
    if Input.is_action_just_pressed("ui_accept") and is_on_floor():
        velocity.y = jump_velocity
        if anim_player: anim_player.play("jump")

    # الحركة
    var input_dir := Input.get_vector("ui_left", "ui_right", "ui_up", "ui_down")
    var direction := (transform.basis * Vector3(input_dir.x, 0, input_dir.y)).normalized()
    
    if direction:
        velocity.x = direction.x * speed
        velocity.z = direction.z * speed
        if anim_player and is_on_floor(): anim_player.play("run")
    else:
        velocity.x = move_toward(velocity.x, 0, speed)
        velocity.z = move_toward(velocity.z, 0, speed)
        if anim_player and is_on_floor(): anim_player.play("idle")

    move_and_slide()
