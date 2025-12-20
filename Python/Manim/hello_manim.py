from manim import *

class HelloManim(Scene):
    def construct(self):
        text = Text("Hello, Manim!")
        self.play(Write(text))
        self.wait()

#  manim -pqh hello_manim.py HelloManim