from manim import *

class SquareScene(Scene):
    def construct(self):
        sq = Square(
            2, stroke_color=WHITE, fill_color=BLUE, fill_opacity=0.75
        )

        self.play(Create(sq), run_time=3)
        self.wait() # by default wait for 1 second

class Name(Scene):
    def construct(self):
        name = Text("Kamal Stark").to_edge(UL, buff=0.5)
        sq = Square(side_length=2, fill_color=RED, fill_opacity=0.75).shift(LEFT * 2)
        tri = Triangle(fill_color=BLUE, fill_opacity=0.75).scale(1.5).to_edge(DR, buff=2)

        self.play(Write(name))
        self.play(DrawBorderThenFill(sq), run_time=2)
        self.play(DrawBorderThenFill(tri), run_time=2)
        self.wait()

        self.play(name.animate.to_edge(UR), run_time=2)
        self.play(sq.animate.scale(1.5), tri.animate.to_edge(DL), run_time=2)
        self.wait()

