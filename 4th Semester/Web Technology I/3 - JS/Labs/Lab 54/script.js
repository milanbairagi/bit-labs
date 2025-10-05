// 14. Array add, remove, display using push, pop, shift, unshift
let arr = [1, 2, 3];

function display() {
	document.getElementById("result").textContent = `Array: [${arr.join(", ")}]`;
}

display();

function addElement() {
	arr.push(prompt("Enter value to push:"));
	display();
}

function removeElement() {
	arr.pop();
	display();
}

function shiftElement() {
	arr.shift();
	display();
}

function unshiftElement() {
	arr.unshift(prompt("Enter value to unshift:"));
	display();
}
