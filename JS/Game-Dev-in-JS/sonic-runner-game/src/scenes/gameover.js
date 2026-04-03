import k from "../kaplayCtx";

export default function gameover(gameMusic) {
  gameMusic.paused = true;

  let bestScore = k.getData("best-score");
  const currentScore = k.getData("current-score");

  const rankGrades = ["F", "E", "D", "C", "B", "A", "S"];
  const rankValues = [50, 80, 100, 150, 200, 300, 500];

  let currentRank = "F";
  let bestRank = "F";

  for (let i = 0; i < rankValues.length; i++) {
    if (rankValues[i] < currentScore) currentRank = rankGrades[i];
    if (rankValues[i] < bestScore) bestRank = rankGrades[i];
  }

  if (bestScore < currentScore) {
    k.setData("best-score", currentScore);
    bestScore = currentScore;
    bestRank = currentRank;
  }

  k.add([
    k.sprite("sonic-bg"),
    k.scale(5.4),
    k.pos(k.center()),
    k.anchor("center"),
  ]);

  k.add([
    k.sprite("game-over-pose"),
    k.scale(3),
    k.pos(k.center()),
    k.anchor("center"),
  ]);

  k.add([
    k.text("GAME-OVER", { font: "mania", size: 124 }),
    k.anchor("center"),
    k.pos(k.center().x, k.center().y - 300),
  ]);

  k.add([
    k.text(`BEST SCORE: ${bestScore}`, {
      font: "mania",
      size: 48,
    }),
    k.anchor("center"),
    k.pos(k.center().x - 500, k.center().y - 160),
  ]);

  k.add([
    k.text(`CURRENT SCORE: ${currentScore}`, {
      font: "mania",
      size: 48,
    }),
    k.anchor("center"),
    k.pos(k.center().x + 500, k.center().y - 160),
  ]);

  const bestRankBox = k.add([
    k.rect(280, 280, { radius: 4 }),
    k.color(0, 0, 0),
    k.opacity(0.4),
    k.area(),
    k.anchor("center"),
    k.outline(6, k.Color.fromArray([255, 255, 255])),
    k.pos(k.center().x - 500, k.center().y + 50),
  ]);

  bestRankBox.add([
    k.text(bestRank, { font: "mania", size: 100 }),
    k.anchor("center"),
  ]);

  const currentRankBox = k.add([
    k.rect(280, 280, { radius: 4 }),
    k.color(0, 0, 0),
    k.opacity(0.4),
    k.area(),
    k.anchor("center"),
    k.outline(6, k.Color.fromArray([255, 255, 255])),
    k.pos(k.center().x + 500, k.center().y + 50),
  ]);

  currentRankBox.add([
    k.text(currentRank, { font: "mania", size: 100 }),
    k.anchor("center"),
  ]);

  k.wait(1, () => {
    const blinking = k.add([
      k.text("Press Space/Click/Touch to Play Again", {
        font: "mania",
        size: 64,
      }),
      k.anchor("center"),
      k.pos(k.center().x, k.center().y + 350),
    ]);
    k.onButtonPress("jump", () => k.go("game"));

    let timer = 0;
    k.onUpdate(() => {
      timer += k.dt();
      if (timer > 0.6) {
        blinking.opacity = blinking.opacity === 0 ? 1 : 0;
        timer = 0;
      }
    });
  });
}
