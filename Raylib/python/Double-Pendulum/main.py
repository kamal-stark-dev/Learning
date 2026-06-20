import math
import random
from collections import deque

from pyray import *
from raylib import *

G = 9.8 # gravitational constant
DEG2RAD = math.pi / 180 # ~ 0.0174533

WIDTH, HEIGHT = 900, 600
start_pos = Vector2(WIDTH / 2, 0)

MASS_RADIUS = 20
LINE_THICKNESS = 2

L1 = 200
L2 = 200

l1, l2, m1, m2, phi1, phi2, phi1_d, phi2_d = 0, 0, 0, 0, 0, 0, 0, 0

TRACE_LEN = 100
trace = deque(maxlen=TRACE_LEN)

def calc_end_pos(l:float, start: Vector2, phi: float) -> Vector2:
    return Vector2(
        start.x + l * math.sin(phi),
        start.y + l * math.cos(phi)
    )


def draw_pendulum(l: float, start: Vector2, phi: float) -> None:
    end = calc_end_pos(l, start, phi)

    draw_line_ex(start, end, LINE_THICKNESS, WHITE)
    draw_circle_v(end, MASS_RADIUS, RED)


def draw_double_pendulum(l1: float, start: Vector2, phi1: float, l2: float, phi2: float) -> None:
    # draw second pendulum
    end_l1 = calc_end_pos(l1, start, phi1)
    draw_pendulum(l2, end_l1, phi2)

    # draw first pendulum later to be on top
    draw_pendulum(l1, start, phi1)

    # draw trace path
    end_l2 = calc_end_pos(l2, end_l1, phi2)
    trace.append(end_l2)
    draw_traces()


def draw_traces():
    r, g, b, a = RED
    for i, point in enumerate(trace):
        a = int((i / TRACE_LEN) * 255)
        draw_circle_v(point, 2, (r, g, b, a))


def init_solver() -> None:
    global l1, l2
    global m1, m2
    global phi1, phi2
    global phi1_d, phi2_d

    l1, l2 = L1, L2
    phi1 = random.randint(-90, 90) * DEG2RAD
    phi2 = random.randint(0, 360) * DEG2RAD
    phi1_d, phi2_d = 0, 0
    m1, m2 = 1, 1


def step(dt) -> None:
    global phi1, phi2
    global phi1_d, phi2_d

    # angular acceleration (according to differential equations)
    phi1_dd = (
        (-G * (2 * m1 + m2) * math.sin(phi1))
        - (m2 * G * math.sin(phi1 - 2 * phi2))
        - (
            2
            * math.sin(phi1 - phi2)
            * m2
            * (
                (phi2_d ** 2) * L2
                + (phi1_d ** 2) * L1 * math.cos(phi1 - phi2)
            )
        )
    ) / (
        L1
        * (
            2 * m1
            + m2
            - m2 * math.cos(2 * phi1 - 2 * phi2)
        )
    )

    phi2_dd = (
        2
        * math.sin(phi1 - phi2)
        * (
            (phi1_d ** 2) * L1 * (m1 + m2)
            + G * (m1 + m2) * math.cos(phi1)
            + (phi2_d ** 2) * L2 * m2 * math.cos(phi1 - phi2)
        )
    ) / (
        L2
        * (
            2 * m1
            + m2
            - m2 * math.cos(2 * phi1 - 2 * phi2)
        )
    )

    # angular velocity
    phi1_d += phi1_dd * dt
    phi2_d += phi2_dd * dt

    # angle itself
    phi1 += phi1_d * dt
    phi2 += phi2_d * dt


# ---------------- MAIN ----------------

init_window(WIDTH, HEIGHT, "Double Pendulum")

init_solver()
set_target_fps(60)
while not window_should_close():
    dt = get_frame_time()
    step(dt * 10)

    if (is_key_pressed(KEY_SPACE)):
        trace.clear()
        init_solver()

    begin_drawing()

    clear_background(BLACK)
    draw_double_pendulum(L1, start_pos, phi1, L2, phi2)

    end_drawing()

close_window()