extends Control
class_name RadialMenu

var is_open: bool = false
var buttons: Array[Button] = []

func _ready():
    # إخفاء القائمة في البداية
    hide()
    # إعداد أزرار القائمة
    add_menu_button("➕ مجسم")
    add_menu_button("🏃 شخصية")
    add_menu_button("💡 إضاءة")
    add_menu_button("▶️ تشغيل")

func add_menu_button(text: String):
    var btn = Button.new()
    btn.text = text
    btn.custom_minimum_size = Vector2(100, 100)
    btn.add_theme_font_size_override("font_size", 20)
    add_child(btn)
    buttons.append(btn)

func toggle_menu():
    is_open = not is_open
    visible = is_open
    if is_open:
        update_buttons_positions()

func update_buttons_positions():
    var center = get_viewport_rect().size / 2
    var radius = 150.0
    for i in range(buttons.size()):
        var angle = (float(i) / buttons.size()) * TAU - (PI / 2)
        var pos = center + Vector2(cos(angle), sin(angle)) * radius
        buttons[i].position = pos - (buttons[i].custom_minimum_size / 2)
