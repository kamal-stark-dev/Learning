import { formatCurrency } from "../scripts/utils/money.js";

// automated test
console.log("test suite: formatCurrency");

// test case 1 (basic)
console.log("cents to dollars");
if (formatCurrency(2095) === "20.95") {
  console.log("passed");
} else {
  console.log("failed");
}

// test case 2 (edge)
console.log("when cents are zero");
if (formatCurrency(0) === "0.00") {
  console.log("0 - passed");
} else {
  console.log("0 - failed");
}

// test case 3 (edge)
console.log("rounds up to the nearest cent");
if (formatCurrency(2000.5) === "20.01") {
  console.log("2000.5 - passed");
} else {
  console.log("2000.5 - failed");
}
