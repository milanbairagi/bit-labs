// 7. Factorial function using for loop
function factorial(n) {
	let fact = 1;
	for (let i = 2; i <= n; i++) fact *= i;
	return fact;
}
function showFactorial() {
	const n = parseInt(document.getElementById("num").value);
	document.getElementById("result").textContent = `Factorial: ${factorial(
		n
	)}`;
}
