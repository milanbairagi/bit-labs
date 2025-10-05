// 8. Palindrome checker function
function isPalindrome(str) {
	str = str.toLowerCase();
	return str === str.split("").reverse().join("");
}
function checkPalindrome() {
	const s = document.getElementById("str").value;
	document.getElementById("result").textContent = isPalindrome(s)
		? "Palindrome"
		: "Not a palindrome";
}
