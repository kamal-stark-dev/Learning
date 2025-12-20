from manim import *

class ValTracker(Scene):
    def construct(self):
        k = ValueTracker(0)

        num = always_redraw(
            lambda: DecimalNumber(
                k.get_value(),
                num_decimal_places=2
            ).scale(1.5)
        )

        self.play(FadeIn(num))

        self.play(k.animate.set_value(5), run_time=5, rate_func=linear)
        self.wait()

class Graphing(Scene):
    def construct(self):
        main_color = BLUE
        axes = Axes(
            x_range=[-6,6,2],
            y_range=[0,30,5],
            x_length=7,
            y_length=5,
            axis_config={"include_numbers": True},
        ).to_edge(DOWN)
        labels = axes.get_axis_labels(x_label="x", y_label="f(x)")

        parab = axes.plot(lambda x: x**2, x_range=[-5, 5], color=main_color)
        func_label = MathTex("f(x) = x^2").next_to(parab, UP, buff=1.5).set_color(main_color)

        area = axes.get_riemann_rectangles(graph=parab, x_range=[-5, 5], dx=0.2, stroke_width=0.1, stroke_color=WHITE)

        self.play(DrawBorderThenFill(axes))
        self.play(Create(parab, run_time=2))
        self.play(Write(labels, run_time=2))
        self.play(Write(func_label))
        self.wait()
        self.play(Create(area, run_time=2))
        self.wait()

class Image_SVG(Scene):
    def construct(self):
        ThreeB1B_icon = SVGMobject("./3b1b.svg").scale(1.5)
        grant_img = ImageMobject("./grant.png").scale(0.65).shift(RIGHT * 2)
        manim_img = ImageMobject("./manim.png").scale(0.9)

        name = always_redraw(lambda: Text("Grant Sanderson", font_size=48).next_to(grant_img, DOWN))

        self.play(DrawBorderThenFill(ThreeB1B_icon, run_time=1.5))
        self.play(ThreeB1B_icon.animate.to_edge(UL, buff=1))

        self.play(FadeIn(manim_img))
        self.play(manim_img.animate.to_edge(DL))

        self.play(FadeIn(grant_img, run_time=2))
        self.play(Write(name))
        self.play(grant_img.animate.to_edge(RIGHT))

        self.wait()