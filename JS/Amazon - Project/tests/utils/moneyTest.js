import { formatCurrency } from "../../scripts/utils/money.js";

describe("test suite: formatCurrency", () => {
  // test 1
  it("convert cents into dollars", () => {
    expect(formatCurrency(2095)).toEqual("20.95");
  });

  // test 2
  it("works with 0", () => {
    expect(formatCurrency(0)).toEqual("0.00");
  });

  // test 3
  it("rounds up to the nearest cent", () => {
    expect(formatCurrency(2000.5)).toEqual("20.01");
  });
});
