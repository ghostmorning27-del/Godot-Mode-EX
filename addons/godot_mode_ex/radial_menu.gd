extends Control
class_name SmartRadialMenu

@export var menu_radius: float = 150.0
var is_open: bool = false
var buttons: Array[Button] = []

func _ready():
    hide()
    # إضافة الأزرار الدائرية
    add_menu_button("إضافة مجسم", 0)
    add_menu_button("إضافة شخصية", 90)
    add_menu_button("إضاءة", 180)
    add_menu_button("تشغيل", 270)

func add_menu_button(text: String, angle_degrees: float):
    var btn = Button.new()
    btn.text = text
    btn.custom_minimum_size = Vector2(80, 80)
    add_child(btn)
    var angle_rad = deg_to_rad(angle_degrees)
    btn.position = Vector2(cos(angle_rad) * menu_radius, sin(angle_rad) * menu_radius)
    buttons.append(btn)

func toggle_menu():
    is_open = not is_open
    visible = is_open
