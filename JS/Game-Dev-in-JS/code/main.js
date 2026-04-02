import kaplay from "kaplay";

kaplay();
loadBean();
setGravity(1600);

add([
  rect(width(), height()),
  outline(4),
  area(),
  pos(0, 0),
  z(0),
  color(135, 186, 255),
]);

const player = add([sprite("bean"), pos(center()), area(), body(), z(10)]);

add([
  rect(width(), 48),
  outline(4),
  area(),
  pos(0, height() - 48),
  body({ isStatic: true }),
  z(10),
  color(124, 252, 0),
]);

onKeyPress("space", () => {
  if (player.isGrounded()) {
    player.jump();
  }
});
