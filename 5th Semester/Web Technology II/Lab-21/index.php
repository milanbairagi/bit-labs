<?php
session_start();

$message = "";

if ($_SERVER["REQUEST_METHOD"] === "POST") {
	$action = $_POST["action"] ?? "";

	if ($action === "start") {
		$_SESSION["student"] = "WT-II Lab Student";
		$message = "Session variable started.";
	} elseif ($action === "end") {
		unset($_SESSION["student"]);
		session_destroy();
		$message = "Session ended.";
	}
}

$currentValue = $_SESSION["student"] ?? "Not set";
?>

<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Lab 21 - Session Start and End</title>
	<style>
		body { font-family: Arial, sans-serif; margin: 40px; }
		button { margin-right: 10px; padding: 8px 14px; }
	</style>
</head>
<body>
	<h2>Lab 21: Start and End Session Variable</h2>

	<?php if ($message !== ""): ?>
		<p><strong><?php echo htmlspecialchars($message); ?></strong></p>
	<?php endif; ?>

	<p>
		Current value of session variable <strong>student</strong>:
		<strong><?php echo htmlspecialchars($currentValue); ?></strong>
	</p>

	<form method="post">
		<button type="submit" name="action" value="start">Start Session</button>
		<button type="submit" name="action" value="end">End Session</button>
	</form>
</body>
</html>
