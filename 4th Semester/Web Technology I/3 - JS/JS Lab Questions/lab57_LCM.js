// Programmed by Milan Bairagi
// Q17: Write a JavaScript program to find the LCM of two numbers.
let a = 12, b = 18;
let gcd = (x, y) => y ? gcd(y, x % y) : x;
let lcm = a * b / gcd(a, b);
console.log("LCM:", lcm);
console.log("Programmed by Milan Bairagi");
