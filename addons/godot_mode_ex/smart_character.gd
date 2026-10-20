extends CharacterBody3D
class_name SmartCharacter

@export var speed: float = 5.0
@export var jump_velocity: float = 4.5
@export var joystick: VirtualJoystick
@export var camera_3d: Camera3D
@export var anim_player: AnimationPlayer

var gravity: float = ProjectSettings.get_setting("physics/3d/default_gravity")

func _physics_process(delta: float) -> void:
    # 1. تطبيق الجاذبية
    if not is_on_floor():
        velocity.y -= gravity * delta

    # 2. الحركة باستخدام عصا التحكم اللمسية
    var input_dir := Vector2.ZERO
    if joystick:
        input_dir = joystick.output

    var direction := (transform.basis * Vector3(input_dir.x, 0, input_dir.y)).normalized()
    
    if direction:
        velocity.x = direction.x * speed
        velocity.z = direction.z * speed
        # تشغيل أنيميشن الركض إذا كان موجوداً
        if anim_player and is_on_floor(): anim_player.play("run")
        # تدوير الشخصية باتجاه الحركة
        if camera_3d:
            var target_angle = atan2(-direction.x, -direction.z)
            rotation.y = lerp_angle(rotation.y, target_angle, 10 * delta)
    else:
        velocity.x = move_toward(velocity.x, 0, speed)
        velocity.z = move_toward(velocity.z, 0, speed)
        if anim_player and is_on_floor(): anim_player.play("idle")

    move_and_slide()

# دالة القفز (يمكن ربطها بزر لمسي)
func jump():
    if is_on_floor():
        velocity.y = jump_velocity
        if anim_player: anim_player.play("jump")
