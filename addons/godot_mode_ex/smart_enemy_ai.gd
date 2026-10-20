extends CharacterBody3D
class_name SmartEnemyAI

@export var speed: float = 3.0
@export var attack_range: float = 2.0
@export var damage: float = 10.0
@export var target: Node3D
@export var anim_player: AnimationPlayer

var gravity: float = ProjectSettings.get_setting("physics/3d/default_gravity")
var is_attacking: bool = false
var start_position: Vector3

func _ready():
    start_position = global_position

func _physics_process(delta: float) -> void:
    if not is_on_floor():
        velocity.y -= gravity * delta

    if target:
        var distance = global_position.distance_to(target.global_position)
        
        if distance <= attack_range:
            # الهجوم
            velocity.x = 0
            velocity.z = 0
            if not is_attacking:
                is_attacking = true
                if anim_player: anim_player.play("attack")
                print("العدو يهاجم اللاعب!")
        else:
            # المطاردة
            is_attacking = false
            var direction = (target.global_position - global_position).normalized()
            velocity.x = direction.x * speed
            velocity.z = direction.z * speed
            if anim_player: anim_player.play("run")
            # تدوير العدو نحو اللاعب
            look_at(Vector3(target.global_position.x, global_position.y, target.global_position.z), Vector3.UP)
    else:
        # العودة للمكان الأصلي إذا لم يوجد هدف
        var direction_to_start = (start_position - global_position).normalized()
        if global_position.distance_to(start_position) > 0.5:
            velocity.x = direction_to_start.x * speed
            velocity.z = direction_to_start.z * speed
            if anim_player: anim_player.play("walk")
        else:
            velocity.x = 0
            velocity.z = 0
            if anim_player: anim_player.play("idle")

    move_and_slide()
