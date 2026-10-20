extends Control
class_name VirtualJoystick

@export var base_radius: float = 100.0
@export var knob_radius: float = 40.0
var output: Vector2 = Vector2.ZERO
var is_pressed: bool = false
var touch_index: int = -1

func _ready():
    custom_minimum_size = Vector2(base_radius * 2, base_radius * 2)

func _gui_input(event):
    if event is InputEventScreenTouch:
        if event.pressed and touch_index == -1:
            touch_index = event.index
            is_pressed = true
            update_joystick(event.position)
        elif not event.pressed and event.index == touch_index:
            touch_index = -1
            is_pressed = false
            output = Vector2.ZERO
            queue_redraw()
            
    if event is InputEventScreenDrag and event.index == touch_index:
        update_joystick(event.position)

func update_joystick(pos: Vector2):
    var center = size / 2
    var diff = pos - center
    if diff.length() > base_radius:
        diff = diff.normalized() * base_radius
    output = diff / base_radius
    queue_redraw()

func _draw():
    var center = size / 2
    draw_circle(center, base_radius, Color(0.5, 0.5, 0.5, 0.5))
    draw_circle(center + (output * base_radius), knob_radius, Color(1, 1, 1, 0.8))
