<!-- 
17. Write a PHP program in which user inputs form data, calculate simple interest
and display it in textbox
-->

<!DOCTYPE html>
<html>
<head>
    <title>Simple Interest Calculator</title>
</head>
<body>
    <form method="post">
        <label for="principal">Principal Amount:</label>
        <input type="number" id="principal" name="principal" required><br>

        <label for="rate">Rate of Interest:</label>
        <input type="number" id="rate" name="rate" step="0.01" required><br>

        <label for="time">Time (in years):</label>
        <input type="number" id="time" name="time" step="0.01" required><br>

        <input type="submit" value="Calculate Simple Interest">
    </form>

    <?php
        $simple_interest = null;
        if ($_POST) {
            $principal = $_POST['principal'];
            $rate = $_POST['rate'];
            $time = $_POST['time'];
            $simple_interest = ($principal * $rate * $time) / 100;
        }

        if ($simple_interest) {
            echo "Simple Interest: " . $simple_interest;
        }
    ?>
</body>
</html>