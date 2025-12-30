// logic goes brrr...

// there is no need to use the line below as the "id" is a valid js variable name, we can directly use it.
// const canvas = document.getElementById("canvas");

const WIDTH = 800;
const HEIGHT = 800;

canvas.width = WIDTH;
canvas.height = HEIGHT;

const BACKGROUND = "#ffffff";
const FOREGROUND = "#EDF2F4";

const ctx = canvas.getContext("2d");

function line(x1, y1, x2, y2, line_width = 1) {
  ctx.save(); // save the current state
  ctx.lineWidth = line_width;
  ctx.beginPath();
  ctx.moveTo(x1, y1);
  ctx.lineTo(x2, y2);
  ctx.stroke();
  ctx.restore(); // restore to previous state
}

function circle(
  x,
  y,
  radius,
  startAngle,
  endAngle,
  line_width = 1,
  counter_clockwise = false
) {
  ctx.save();
  ctx.lineWidth = line_width;
  ctx.beginPath();
  ctx.arc(x, y, radius, startAngle, endAngle, counter_clockwise);
  ctx.fillStyle = "red";
  ctx.fill();
  ctx.stroke();
  ctx.closePath();
  ctx.restore();
}

function arcPath(
  path,
  x,
  y,
  radius,
  startAngle,
  endAngle,
  counter_clockwise = false
) {
  const sx = x + Math.cos(startAngle) * radius;
  const sy = y + Math.sin(startAngle) * radius;
  path.moveTo(sx, sy);
  path.arc(x, y, radius, startAngle, endAngle, counter_clockwise);
}

function text(
  text,
  x,
  y,
  color = "#000000",
  font = "32px Arial",
  style = "normal"
) {
  ctx.save();
  ctx.font = font;

  if (style == "normal") {
    ctx.fillStyle = color;
    ctx.fillText(text, x, y);
  } else if (style == "stroke") {
    ctx.fillStyle = color;
    ctx.strokeText(text, x, y);
  } else {
    console.log("Invalid style selected.");
  }
  ctx.restore();
}

function image(path, x, y, scale = 1, alpha = 1) {
  ctx.save();
  const img = new Image();
  img.src = path;

  const w = img.width * scale;
  const h = img.height * scale;

  img.onload = () => {
    ctx.globalAlpha = alpha;
    ctx.drawImage(img, x, y, w, h);
    // ctx.globalAlpha = 1.0;
  };
  ctx.restore();
}

function grid(x, y, width, height, n, m, line_width) {
  const stepY = grid_height / n;
  for (let i = 0; i <= n; i++) {
    line(
      gridX,
      gridY + i * stepY,
      gridX + grid_width,
      gridY + i * stepY,
      line_width
    );
  }

  const stepX = grid_width / m;
  for (let i = 0; i <= m; i++) {
    line(
      gridX + i * stepX,
      gridY,
      gridX + i * stepX,
      gridY + grid_height,
      line_width
    );
  }
}

// filling the canvas
ctx.fillStyle = BACKGROUND;
ctx.fillRect(0, 0, WIDTH, HEIGHT);

// 3 x 3 grid
const grid_width = 600;
const grid_height = 600;
const gridX = 100;
const gridY = 100;

grid(gridX, gridY, grid_width, grid_height, 3, 3, (line_width = 2.5));

// wierd nike shape
const step = grid_width / 3;
const shape = new Path2D();

ctx.save();
ctx.beginPath();

// arc 1
arcPath(shape, gridX, gridY, 3 * step, 0, Math.PI / 2);

// arc 2
arcPath(
  shape,
  gridX + 2 * step,
  gridY + 3 * step,
  2 * step,
  Math.PI,
  Math.PI * 1.5
);

// arc 3
arcPath(
  shape,
  gridX + 2 * step,
  gridY + 2 * step,
  step,
  Math.PI,
  Math.PI * 1.5
);

// arc 4
arcPath(shape, gridX + step, gridY, 2 * step, 0, Math.PI / 2);

ctx.closePath();

ctx.fillStyle = "rgba(255, 0, 0, 0.75)";
ctx.fill(shape, "evenodd");

ctx.lineWidth = 4;
ctx.stroke(shape);

ctx.restore();

// label for size
text("Find the Area", 300, 70, "black", "32px Arial");
line(710, 500, 722, 500, 4);
line(720, 500, 720, 700, 4);
line(710, 700, 722, 700, 4);
text("4", 730, 610, "black", "32px Arial");
