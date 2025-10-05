// 5. Find largest of three numbers using prompt and if...else
function findLargest() {
	let a = parseFloat(prompt("Enter first number:"));
	let b = parseFloat(prompt("Enter second number:"));
	let c = parseFloat(prompt("Enter third number:"));
	let largest;
	if (a >= b && a >= c) largest = a;
	else if (b >= a && b >= c) largest = b;
	else largest = c;
	document.getElementById("result").textContent = `Largest: ${largest}`;
}
