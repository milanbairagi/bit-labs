// 16. Random number between 1 and 100, check even/odd
function showRandom() {
	const n = Math.floor(Math.random() * 100) + 1;
	const type = n % 2 === 0 ? "Even" : "Odd";
	document.getElementById("result").textContent = `Random: ${n} (${type})`;
}
