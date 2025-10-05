// Programmed by Milan Bairagi
// Q14: Write a JavaScript program to check if a number is prime.
let n = 7, isPrime = n > 1;
for(let i = 2; i <= Math.sqrt(n); i++)
  if(n % i === 0) isPrime = false;
console.log(n + " is Prime:", isPrime);
console.log("Programmed by Milan Bairagi");
