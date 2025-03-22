/*
#TODO: Add Local Storage for saving colors, size and color.
*/

const container = document.querySelector(".container");

const randomColorEl = document.querySelector("#random-color");
const colorSelectorEL = document.querySelector("#color-selector");
let selectedColor = "#40d540";
colorSelectorEL.value = selectedColor;
const clearBoardEL = document.querySelector("#clear-board");

const resize = document.querySelector("#resize");

randomColorEl.addEventListener("click", () => {
  randomOn = true;
});

colorSelectorEL.addEventListener("click", (event) => {
  selectedColor = event.target.value;
  randomOn = false;
});

let spacePressed = false;
clearBoardEL.addEventListener("click", clearBoard);
document.addEventListener("keydown", (event) => {
  if (event.key === "c") {
    clearBoard();
  }
  if (event.key === "r") {
    randomOn = true;
  }
  if (event.key === "b") {
    randomOn = false;
  }
  if (event.key === "e") {
    eraserOn = true;
  }
  if (event.key === " ") {
    spacePressed = true;
  }
});

document.addEventListener("keyup", (event) => {
  if (event.key === " ") {
    spacePressed = false;
  }
  if (event.key === "e") {
    eraserOn = false;
  }
});

document.querySelector("#grid-size").addEventListener("keydown", (event) => {
  if (event.key == "Enter") {
    squares = document.querySelector("#grid-size").value;
    drawGrid(squares);
  }
});

resize.addEventListener("click", () => {
  squares = document.querySelector("#grid-size").value;
  drawGrid(squares);
});

function clearBoard() {
  const blocks = document.querySelectorAll(".block");
  blocks.forEach((block) => (block.style.backgroundColor = "white"));
}

let randomOn = true;
function drawGrid(squares) {
  container.innerHTML = "";
  for (let i = 0; i < squares; i++) {
    const row = document.createElement("div");
    row.classList.add("row");
    for (let j = 0; j < squares; j++) {
      const block = document.createElement("div");
      block.classList.add("block");
      block.style.width = `${600 / squares}px`;

      block.addEventListener("mouseover", (e) => {
        if (!spacePressed) {
          if (randomOn) {
            e.target.style.backgroundColor = randomColor();
          } else {
            e.target.style.backgroundColor = selectedColor;
          }
          if (eraserOn) {
            e.target.style.backgroundColor = "#ffffff";
          }
        }
      });
      row.appendChild(block);
    }
    container.appendChild(row);
  }
}

function randomColor() {
  let color = "#";
  const characters = "0123456789abcdef";
  for (let i = 0; i < 6; i++) {
    color += characters[Math.floor(Math.random() * 16)];
  }
  return color;
}

let squares = 16;
drawGrid(squares);
