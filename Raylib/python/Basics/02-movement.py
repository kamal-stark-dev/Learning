from pyray import *
from raylib import *
from os.path import join

init_window(900, 600, "Movement")

player_pos = Vector2(0, 0)

# set_target_fps(60)

while not window_should_close():
    # updating
    dt = get_frame_time()
    player_pos.x += 10 * dt

    # drawing
    begin_drawing()

    clear_background(WHITE)

    draw_rectangle_v(player_pos, (40, 40), RED)

    draw_fps(0, 0)

    end_drawing()

close_window()
