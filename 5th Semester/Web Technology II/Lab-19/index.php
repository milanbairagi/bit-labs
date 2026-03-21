<?php
$host = "localhost";
$username = "noname";
$password = "noname123";
$database = "wt2_lab18_db";
$table = "customers";
$city = "Pokhara";

$conn = new mysqli($host, $username, $password, $database);

if ($conn->connect_error) {
	die("Connection failed: " . $conn->connect_error);
}

// Query to fetch customers from Pokhara city
$sql = "SELECT * FROM $table WHERE city = ?";
$stmt = $conn->prepare($sql);

if (!$stmt) {
	die("Prepare failed: " . $conn->error);
}

$stmt->bind_param("s", $city);
$stmt->execute();
$result = $stmt->get_result();

$customers = [];
if ($result->num_rows > 0) {
	while ($row = $result->fetch_assoc()) {
		$customers[] = $row;
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
	<title>Customers from Pokhara</title>
	<style>
		table {
			border-collapse: collapse;
		}
		th, td {
			border: 1px solid #ddd;
			padding: 10px;
			text-align: left;
		}
	</style>
</head>
<body>
	<h2>Customers from <?php echo $city; ?> City</h2>
	
	<?php if (count($customers) > 0): ?>
		<p>Found <?php echo count($customers); ?> customer(s) from <?php echo $city; ?></p>
		<table>
			<thead>
				<tr>
					<th>ID</th>
					<th>Name</th>
					<th>Email</th>
					<th>Phone</th>
					<th>City</th>
					<th>Created At</th>
				</tr>
			</thead>
			<tbody>
				<?php foreach ($customers as $customer): ?>
					<tr>
						<td><?php echo htmlspecialchars($customer['id']); ?></td>
						<td><?php echo htmlspecialchars($customer['name']); ?></td>
						<td><?php echo htmlspecialchars($customer['email']); ?></td>
						<td><?php echo htmlspecialchars($customer['phone']); ?></td>
						<td><?php echo htmlspecialchars($customer['city']); ?></td>
						<td><?php echo htmlspecialchars($customer['created_at']); ?></td>
					</tr>
				<?php endforeach; ?>
			</tbody>
		</table>
	<?php else: ?>
		<p>No customers found from <?php echo $city; ?> city.</p>
	<?php endif; ?>
	
	<p><strong>Database:</strong> <?php echo $database; ?></p>
	<p><strong>Table:</strong> <?php echo $table; ?></p><br>
	<p>Programmed by Milan Bairagi...</p>
</body>
</html>