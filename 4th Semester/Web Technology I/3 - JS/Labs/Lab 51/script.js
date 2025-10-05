// 11. Change background color on button click
const btn = document.getElementById("colorBtn");
btn.addEventListener("click", function () {
	// document.body.style.backgroundColor = "#" + Math.floor(Math.random() * 16777215).toString(16);
  // document.body.style.backgroundColor = `rgb(${Math.random() * 255}, ${Math.random() * 255}, ${Math.random() * 255})`;
  document.body.style.backgroundColor = "lightblue";
});
