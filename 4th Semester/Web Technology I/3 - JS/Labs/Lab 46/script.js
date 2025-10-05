// 6. FizzBuzz from 1 to 100
let result = "";
for (let i = 1; i <= 100; i++) {
	if (i % 3 === 0 && i % 5 === 0) result += "FizzBuzz, ";
	else if (i % 3 === 0) result += "Fizz, ";
	else if (i % 5 === 0) result += "Buzz, ";
	else result += i + ", ";
}
document.getElementById("output").textContent = result;
