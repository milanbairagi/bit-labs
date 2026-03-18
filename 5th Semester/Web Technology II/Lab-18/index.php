<!-- 
18. Write a program to insert 5 customers record in database. Assume database
name and table name yourself
-->

<?php
$host = "localhost";
$username = "noname";
$password = "noname123";
$database = "wt2_lab18_db";
$table = "customers";

$conn = new mysqli($host, $username, $password);

if ($conn->connect_error) {
	die("Connection failed: " . $conn->connect_error);
}

// Create database and table if they do not exist.
$conn->query("CREATE DATABASE IF NOT EXISTS $database");
$conn->select_db($database);

$createTableSql = "
	CREATE TABLE IF NOT EXISTS $table (
		id INT AUTO_INCREMENT PRIMARY KEY,
		name VARCHAR(100) NOT NULL,
		email VARCHAR(100) NOT NULL,
		phone VARCHAR(15) NOT NULL,
		city VARCHAR(50) NOT NULL,
		created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
	)
";

if (!$conn->query($createTableSql)) {
	die("Table creation failed: " . $conn->error);
}

$customers = [
	["Aarav Sharma", "aarav.sharma@example.com", "9841000001", "Kathmandu"],
	["Sita Karki", "sita.karki@example.com", "9841000002", "Pokhara"],
	["Rohan Adhikari", "rohan.adhikari@example.com", "9841000003", "Lalitpur"],
	["Nisha Gautam", "nisha.gautam@example.com", "9841000004", "Bhaktapur"],
	["Bikash Thapa", "bikash.thapa@example.com", "9841000005", "Pokhara"]
];

$insertSql = "INSERT INTO $table (name, email, phone, city) VALUES (?, ?, ?, ?)";
$stmt = $conn->prepare($insertSql);

if (!$stmt) {
	die("Prepare failed: " . $conn->error);
}

$inserted = 0;

foreach ($customers as $customer) {
	[$name, $email, $phone, $city] = $customer;
	$stmt->bind_param("ssss", $name, $email, $phone, $city);

	if ($stmt->execute()) {
		$inserted++;
	}
}

$stmt->close();
$conn->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Insert Customers</title>
	<style>
		.ok {
			color: #0a7a1f;
			font-weight: bold;
		}
	</style>
</head>
<body>
	<h2>Customer Insertion Program</h2>
	<p class="ok"><?php echo $inserted; ?> out of 5 customer records inserted successfully.</p>
	<p><strong>Database:</strong> <?php echo $database; ?></p>
	<p><strong>Table:</strong> <?php echo $table; ?></p>
</body>
</html>
