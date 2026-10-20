extends Node3D
class_name MobileCamera

@export var sensitivity: float = 0.005
@export var min_pitch: float = -80.0
@export var max_pitch: float = 80.0
var pitch: float = 0.0
var yaw: float = 0.0

func _ready():
    yaw = rotation.y

func _unhandled_input(event):
    # التحقق من السحب باللمس (Touch Drag)
    if event is InputEventScreenDrag:
        yaw -= event.relative.x * sensitivity
        pitch -= event.relative.y * sensitivity
        pitch = clamp(pitch, deg_to_rad(min_pitch), deg_to_rad(max_pitch))
        
        # تطبيق الدوران
        rotation.y = yaw
        rotation.x = pitch
