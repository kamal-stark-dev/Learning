from manim import *

class HelloManim(Scene):
    def construct(self):
        text = Text("Hello, Manim!")
        self.play(Write(text))
        self.wait()

class HelloWorld(Scene):
    def construct(self):
        circle = Circle()
        square = Square(stroke_color=GREEN)
        triangle = Triangle().shift(UR)

        text = Text("Learn with Kamalveer!", font_size=42)

        self.play(Write(text, run_time=3))
        self.play(text.animate.to_edge(UP, buff=0.9), run_time=1.5)
        self.play(Create(circle))
        self.play(Create(square))
        self.play(square.animate.shift(DL))
        self.play(Transform(text[-1], triangle, run_time=1.5))
        self.wait()