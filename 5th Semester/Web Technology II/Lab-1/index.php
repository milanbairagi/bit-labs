<?php
// 1. Write a PHP program to print sum of digits.
$number = 123456;
$sum = 0;
$temp = $number;

while ($temp > 0) {
    $sum += $temp % 10;
    $temp = (int)($temp / 10);
}

echo "Number: $number\n";
echo "Sum of digits: $sum\n";

echo "\nProgrammed by Milan Bairagi..."
?>
