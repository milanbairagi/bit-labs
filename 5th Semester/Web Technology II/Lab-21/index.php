<?php
session_start();
if (isset($_POST["username"])) {
	$_SESSION["username"] = $_POST["username"];
}
if (isset($_POST["destroy_session"])) {
    session_unset();
    session_destroy();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Session</title>
</head>
<body>
    <form method="post">
        <label for="username">Username:</label>
        <input type="text" id="username" name="username" required><br>
        <button type="submit">Submit</button>
    </form>
    <a href="home.php">Go to Home</a>
    <form method="post">
        <button type="submit" name="destroy_session">Destroy Session</button>
    </form>
</body>
</html>