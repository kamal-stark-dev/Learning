from pyray import *
from raylib import ffi

# -----------------------------------
# WINDOW
# -----------------------------------

init_window(800, 450, "Raylib UI Example")
set_target_fps(60)

# -----------------------------------
# VARIABLES
# -----------------------------------

# Pointer values
fullscreen = ffi.new("bool *", False)
player_speed = ffi.new("float *", 5.0)

# NORMAL bool for textbox
edit_mode = True

# Proper C text buffer
name_buffer = ffi.new("char[64]", b"Player")

# -----------------------------------
# MAIN LOOP
# -----------------------------------

while not window_should_close():

    # -----------------------------------
    # UI
    # -----------------------------------

    gui_check_box(
        Rectangle(20, 20, 20, 20),
        "Fullscreen",
        fullscreen
    )

    gui_slider_bar(
        Rectangle(20, 60, 200, 20),
        "Slow",
        "Fast",
        player_speed,
        1.0,
        20.0
    )

    edit_mode = gui_text_box(
        Rectangle(20, 100, 200, 30),
        name_buffer,
        64,
        edit_mode
    )

    # -----------------------------------
    # CONVERT VALUES
    # -----------------------------------

    fullscreen_value = fullscreen[0]
    speed_value = player_speed[0]

    player_name = ffi.string(name_buffer).decode("utf-8")

    # -----------------------------------
    # DRAW
    # -----------------------------------

    begin_drawing()

    clear_background(RAYWHITE)

    draw_text(
        f"Player: {player_name}",
        20,
        180,
        20,
        BLACK
    )

    draw_text(
        f"Speed: {speed_value:.1f}",
        20,
        210,
        20,
        BLACK
    )

    draw_text(
        f"Fullscreen: {fullscreen_value}",
        20,
        240,
        20,
        BLACK
    )

    end_drawing()

# -----------------------------------
# CLEANUP
# -----------------------------------

close_window()