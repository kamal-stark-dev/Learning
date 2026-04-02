import kaplay from "kaplay";

const k = kaplay({
  width: 1280,
  height: 720,
});

k.loadBean();
k.setGravity(1800);

k.add([k.rect(k.width(), k.height()), k.pos(0, 0), k.color(155, 155, 255)]);

const player = k.add([
  k.sprite("bean"),
  k.pos(k.center()),
  k.area(),
  k.body(),
  k.offscreen(),
]);

player.onKeyPress("space", () => {
  if (player.isGrounded()) player.jump();
});

player.onKeyPress("right", () => {
  player.move(2000, 0);
});

player.onKeyPress("left", () => {
  player.move(-2000, 0);
});

player.onExitScreen(() => {
  k.go("gameover");
});

k.scene("gameover", () => {
  k.add([k.rect(k.width(), k.height()), k.pos(0, 0), k.color(155, 155, 255)]);

  k.add([
    k.text("Game Over", { size: 64 }),
    k.pos(500, 300),
    k.color(255, 0, 0),
  ]);
});

k.add([
  k.rect(k.width(), 200),
  k.pos(0, k.height() - 200),
  k.area(),
  k.body({ isStatic: true }),
  k.outline(3),
  k.color(255, 0, 0),
]);

let counter = 0;
const counterUI = k.add([k.text("Score: 0"), k.pos(15, 15)]);

k.loop(1, () => {
  // update counter
  counter++;
  counterUI.text = "Score: " + counter;

  const speeds = [300, 500, 800];
  const currentSpeed = speeds[Math.floor(Math.random() * speeds.length)];

  k.add([
    k.rect(50, 50),
    k.pos(1200, 500),
    k.area(),
    k.body(),
    k.outline(3),
    k.move(k.vec2(-1, 0), currentSpeed),
  ]);
});
