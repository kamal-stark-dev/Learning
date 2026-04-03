import kaplay from "kaplay";

const k = kaplay({
  width: 1920,
  height: 1080,
  letterbox: true,
  background: [0, 0, 0],
  global: false,
  touchToMouse: true, // for mobile usage (touch input -> clicks)
  buttons: {
    jump: {
      keyboard: ["space", "up"],
      mouse: "left",
    },
  },
  debugKey: "d",
  debug: true, // set it to false after making the game or others will also be able to debug it.
});

export default k;
