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

class Arrow(Scene):
    def construct(self):
        rect = Rectangle(color=WHITE, height=2, width=3).to_edge(UL, buff=1)
        circ = Circle().to_edge(DOWN, buff=1)

        arrow = always_redraw(
            lambda: Line(
                start=rect.get_bottom(), end=circ.get_top()
            ).add_tip()
        )

        self.play(Create(VGroup(rect, circ, arrow)))
        self.wait()

        self.play(rect.animate.to_edge(UR, buff=1).scale(0.5), circ.animate.to_edge(DR, buff=1).scale(0.5))
        self.wait()

class Updaters(Scene):
    def construct(self):
        num = MathTex("log(2)")

        box = always_redraw(lambda: SurroundingRectangle(num, color=WHITE, fill_color=RED, fill_opacity=0.75, buff=0.5))
        box.set_z_index(-1)

        label = always_redraw(lambda: Text("Logarithms").next_to(box, DOWN, buff=0.25))

        self.play(Write(num))
        self.play(Create(box))
        self.play(Write(label))

        self.play(num.animate.shift(RIGHT * 2), run_time=2)

        self.wait()