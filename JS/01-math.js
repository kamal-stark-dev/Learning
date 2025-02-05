// Basic Arithmetic
console.log("Addition:", 2 + 2); // 4
console.log("Subtraction:", 8 - 2); // 6
console.log("Multiplication:", 3 * 4); // 12
console.log("Division:", 10 / 4); // 2.5
console.log("Exponentiation:", 2 ** 3); // 8
console.log("Modulus:", 10 % 3); // 1

// Rounding
console.log(`\nMath.round(2.3) = ${Math.round(2.3)}`);
console.log(`Math.round(2.8) = ${Math.round(2.8)}`);

// Ceil and Floor
console.log(`\nMath.ceil(2.3) = ${Math.ceil(2.3)}`);
console.log(`Math.floor(2.8) = ${Math.floor(2.8)}`);

// Square root
console.log(`\nMath.sqrt(16) = ${Math.sqrt(16)}`);

// Absolute
console.log(`Math.abs(-5) = ${Math.abs(-5)}`);

// Minimum and Maximum
console.log(`\nMath.max(1, 3, 2) = ${Math.max(1, 3, 2)}`);
console.log(`Math.min(1, 3, 2) = ${Math.min(1, 3, 2)}`);

// Random
console.log(`\nMath.random() = ${Math.random()}`);

// Celcius to Fahrenheit
celcius = 25;
fahrenheit = (celcius * 9) / 5 + 32;
console.log(`\n${celcius}°C = ${fahrenheit}°F`);

// Fahrenheit to Celcius
fahrenheit = 86;
celcius = ((fahrenheit - 32) * 5) / 9;
console.log(`${fahrenheit}°F = ${celcius}°C`);
