<!-- 20. Write a program to set cookie value and display it -->
<?php
if (isset($_POST['set_cookie'])) {
	$cookie_name = $_POST['cookie_name'];
	$cookie_value = $_POST['cookie_value'];
	setcookie($cookie_name, $cookie_value, time() + 60 * 60 * 24 * 30, "/"); // 86400 = 1 day
}

$key = null;
$value = null;
if (isset($_POST['display_cookie']) && isset($_COOKIE[$_POST['cookie_name']])) {
    $key = $_POST['cookie_name'];
    $value = $_COOKIE[$key];
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Cookie Program</title>
</head>
<body>
	<h2>Cookie Program</h2>

	<form method="post">
		<label for="cookie_name">Cookie Name:</label>
		<input type="text" id="cookie_name" name="cookie_name" required>
		<br><br>
		<label for="cookie_value">Cookie Value:</label>
		<input type="text" id="cookie_value" name="cookie_value">
		<br><br>
		<input type="submit" name="set_cookie" value="Set Cookie">
        <input type="submit" name="display_cookie" value="Display Cookie">
	</form>

	<?php if (isset($key) && isset($value)): ?>
		<strong>Cookie:</strong><br>
        <strong>
            <?php echo htmlspecialchars($key); ?>
        </strong> :
        <?php echo htmlspecialchars($value); ?>
	<?php endif; ?>

	<p>Programmed by Milan Bairagi...</p>
</body>
</html>