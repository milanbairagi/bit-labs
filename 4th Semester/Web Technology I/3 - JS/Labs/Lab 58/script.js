// 18. Form validation for empty fields
function validateForm() {
	const name = document.getElementById("name").value;
	const email = document.getElementById("email").value;
	const password = document.getElementById("password").value;
	if (!name || !email || !password)
		document.getElementById("result").textContent =
			"All fields are required!";
	// return false;
	else document.getElementById("result").textContent = "Form submitted!";
	// return false;
}

const form = document.getElementById("form");
form.addEventListener("submit", (e) => {
	e.preventDefault();
	validateForm();
});
