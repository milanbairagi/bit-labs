// 17. Email validation using RegExp
function validateEmail() {
	const email = document.getElementById("email").value;
	// const regex = /^[\w.-]+@[\w.-]+\.\w{2,}$/;
	const regex = new RegExp("^[\\w.-]+@[\\w.-]+.\\w{2,}$");
	document.getElementById("result").textContent = regex.test(email)
		? "Valid Email"
		: "Invalid Email";
}
