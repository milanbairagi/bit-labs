// 19. Set and read cookies for theme preference
function getCookies(name) {
  const cookies = document.cookie.split(";");
  for (let cookie of cookies) {
    const [key, value] = cookie.split("=");
    if (key === name) return value;
  }
  return null;
}

function setTheme(theme) {
	document.cookie = `theme=${theme}; path=/;`;
	document.getElementById("result").textContent = `Theme set to ${theme}`;
}
function showTheme() {
	const theme = getCookies("theme");
	document.getElementById("result").textContent = theme
		? `Theme: ${theme}`
		: "No theme set";
}
