const ctx = canvas.getContext("2d");

const SIZE = 600;
canvas.height = SIZE;
canvas.width = SIZE;

ctx.strokeStyle = "lightblue";
ctx.lineWidth = 5;

const sides = 10;

function drawBranch(level, radint, radscale) {
  if (level < 0) return;

  const branchSize = 100;
  ctx.beginPath();
  ctx.moveTo(0, 0);
  ctx.lineTo(branchSize, 0);
  ctx.stroke();

  // updating things

  ctx.save();
  ctx.translate(branchSize, 0);
  ctx.scale(radscale, radscale);

  ctx.save();
  ctx.rotate(radint);
  drawBranch(level - 1, radint, radscale);
  ctx.restore();

  ctx.save();
  ctx.rotate(-radint);
  drawBranch(level - 1, radint, radscale);
  ctx.restore();

  ctx.restore();
}

function drawFractal() {
  ctx.save();
  ctx.translate(SIZE / 2, SIZE / 2);

  const radint = Math.random() * 2;
  const radscale = Math.random();
  const sides = Math.floor(Math.random() * 10);

  for (let i = 0; i < sides; i++) {
    drawBranch(7, radint, radscale);
    ctx.rotate((2 * Math.PI) / sides);
  }
  ctx.restore();
}

drawFractal();
