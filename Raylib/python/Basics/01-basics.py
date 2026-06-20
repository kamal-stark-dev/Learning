from pyray import *
from raylib import *

# to make paths valid for every OS
from os.path import join

init_window(900, 600, "Hello, World!")

PRIMARY_COLOR = (245, 40, 145, 255)

# import
text_card_texture = load_texture(join("assets", "text_card.png"))

while not window_should_close():
    begin_drawing()

    clear_background(WHITE)

    # shapes
    draw_circle(450, 300, 100, PRIMARY_COLOR)

    for radius in range(120, 201, 20):
        draw_circle_lines(450, 300, radius, PRIMARY_COLOR)

    draw_line_ex([0, 0], [900, 600], 4, PRIMARY_COLOR)

    # textures (images)
    draw_texture_ex(text_card_texture, [30, 480], 0, 0.04, WHITE)

    # text
    draw_text("Raylib", 72, 513, 32, WHITE)

    end_drawing()

close_window()