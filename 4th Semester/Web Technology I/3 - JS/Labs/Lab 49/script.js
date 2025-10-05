// 9. Reverse a number using while loop
function reverseNumber() {
	let n = parseInt(document.getElementById("num").value);
	let rev = 0;
	while (n > 0) {
		rev = rev * 10 + (n % 10);
		n = Math.floor(n / 10);
	}
	document.getElementById("result").textContent = `Reversed: ${rev}`;
}
