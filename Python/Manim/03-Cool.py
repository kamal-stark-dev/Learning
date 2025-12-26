from manim import *

class demo(Scene):
    def construct(self):
        sq1 = Square(side_length=1, fill_opacity=1).shift(LEFT * 5)
        sq2 = Square(side_length=1, fill_opacity=1).move_to([5, 0, 0])

        # grid
        # c = NumberPlane().add_coordinates()
        # self.add(c)
        # self.wait()

        self.play(Write(sq1))
        self.play(Write(sq2))

        self.add(Text("")) # slap to manim

        squares = []
        labels = []
        colors = (RED, ORANGE, YELLOW, GREEN, BLUE)
        for i in range(5):
            sq = Square(
                side_length=1,
                fill_opacity=1,
                fill_color=colors[i],
                stroke_color=colors[i]
            )
            squares.append(sq)

            label = Text(str(i + 1)).scale(1.2)
            labels.append(label)

        squares_group = VGroup(*squares).arrange(RIGHT)
        labels_group = VGroup(*labels)

        for label, square in zip(labels_group, squares_group):
            label.next_to(square, UP, buff=0.4)


        self.play(sq2.animate.next_to(sq1, RIGHT))
        self.play(ReplacementTransform(VGroup(sq1, sq2), squares_group))

        border = SurroundingRectangle(squares_group, color=WHITE, buff=0.2)
        self.play(Write(border))

        self.play(Write(labels_group))

        for i in range(5):
            self.play(
                Indicate(labels_group[i], color=colors[i]),
                Indicate(squares_group[i], color=colors[i], scale_factor=0.8)
            )

        dot = Dot(color=RED)
        self.play(ReplacementTransform(VGroup(squares_group, border, labels_group), dot))
        self.play(dot.animate.scale(108))
        self.play(FadeOut(dot))

        self.wait()