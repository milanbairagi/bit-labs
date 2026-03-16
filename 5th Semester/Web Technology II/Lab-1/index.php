<!-- 1. Write a PHP program to print sum of digits. -->
<?php
$number = 123456;
$sum = 0;
$temp = abs($number);

while ($temp > 0) {
    $sum += $temp % 10;
    $temp = (int)($temp / 10);
}

echo "Number: $number\n";
echo "Sum of digits: $sum\n";
?>
