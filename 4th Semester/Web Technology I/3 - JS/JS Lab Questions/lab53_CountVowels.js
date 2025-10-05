// Programmed by Milan Bairagi
// Q13: Write a JavaScript program to count the number of vowels in a string.
let str = "hello world";
let count = (str.match(/[aeiou]/gi) || []).length;
console.log("Vowels:", count);
console.log("Programmed by Milan Bairagi");
