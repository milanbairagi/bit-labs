// Programmed by Milan Bairagi
// Q15: Write a JavaScript program to generate Fibonacci series up to n terms.
let n = 7, a = 0, b = 1;
let fib = [a, b];
for(let i = 2; i < n; i++) fib.push(fib[i-1] + fib[i-2]);
console.log("Fibonacci:", fib.slice(0, n));
console.log("Programmed by Milan Bairagi");
