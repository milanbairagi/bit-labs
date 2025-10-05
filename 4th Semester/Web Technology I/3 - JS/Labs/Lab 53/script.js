// 13. Array sum and average
const arr = [10, 20, 30, 40, 50];
function showSumAvg() {
	// const sum = arr.reduce((a, b) => a + b, 0);
  let sum = 0;
  for (let n of arr) sum += n;

	const avg = sum / arr.length;
	document.getElementById(
		"result"
	).textContent = `Sum: ${sum}, Average: ${avg}`;
}
