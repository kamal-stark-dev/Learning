// logic goes brrr...

const WIDTH = 800;
const HEIGHT = 800;

canvas.width = WIDTH;
canvas.height = HEIGHT;

const BACKGROUND = "#333333";
const FOREGROUND = "#EDF2F4";

const ctx = canvas.getContext("2d");

function line(x1, y1, x2, y2) {
  ctx.beginPath();
  ctx.moveTo(x1, y1);
  ctx.lineTo(x2, y2);
  ctx.stroke();
}

function circle(x, y, radius, startAngle, endAngle, counter_clockwise=false) {
  ctx.beginPath();
  ctx.arc(x, y, radius, startAngle, endAngle, counter_clockwise);
  ctx.stroke();
}

function text(text, x, y, font="32px Arial", style="normal") {
  ctx.font = font;
  if (style == "normal") {
    ctx.fillText(text, x, y);
  }
  else if (style == "stroke") {
    ctx.strokeText(text, x, y);
  }
  else {
    console.log("Invalid style selected.");
  }
}

function image(path, x, y, scale=1, alpha=1) {
  const img = new Image();
  img.src = path;

  const w = img.width * scale;
  const h = img.height * scale;

  img.onload = () => {
    ctx.globalAlpha = alpha;
    ctx.drawImage(img, x, y, w, h);
    ctx.globalAlpha = 1.0;
  }
}

// 3 x 3 grid
const grid_width = 600;
const grid_height = 600;
const gridX = 100;
const gridY = 100;

function grid(x, y, width, height, n, m) {
  const stepY = grid_height / n;
  for (let i = 0; i <= n; i++) {
    line(gridX, gridY + (i * stepY), gridX + grid_width, gridY + (i * stepY));
  }

  const stepX = grid_width / m;
  for (let i = 0; i <= m; i++) {
    line(gridX + (i * stepX), gridY, gridX + (i * stepX), gridY + grid_height);
  }
}

// grid(gridX, gridY, grid_width, grid_height, 3, 3);

// gradient
let grd = ctx.createLinearGradient(0, 0, WIDTH, HEIGHT);
grd.addColorStop(0, "red");
grd.addColorStop(1, "white");

ctx.fillStyle = grd;
ctx.fillRect(0, 0, WIDTH, HEIGHT);

// line
line(0, 0, WIDTH, HEIGHT);

// circle
circle(WIDTH / 2, HEIGHT / 2, HEIGHT / 2, 0, 2 * Math.PI);

// text
text("Hello Mello", WIDTH / 2 - 160, HEIGHT / 2 + 36, "72px Helvetica", "stroke");

// image
image_address = "https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fmedia.cnn.com%2Fapi%2Fv1%2Fimages%2Fstellar%2Fprod%2F150324154003-01-internet-cats-restricted.jpg%3Fq%3Dw_3000&f=1&nofb=1&ipt=91c799ce5dc157b57a8e59d2630a2baae0e33addb24075f228224b0679229a34"
image(image_address, 0, 160, 0.28, 0.5);
grid(gridX, gridY, grid_width, grid_height, 3, 3);
