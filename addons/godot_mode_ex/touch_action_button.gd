extends Button
class_name TouchActionButton

@export var target_character: SmartCharacter

func _ready():
    # ربط إشارة الضغط على الزر بدالة القفز
    button_down.connect(_on_button_down)
    # تكبير الزر ليتناسب مع الهاتف
    custom_minimum_size = Vector2(80, 80)

func _on_button_down():
    if target_character:
        target_character.jump()
        print("تم الضغط على زر القفز!")
