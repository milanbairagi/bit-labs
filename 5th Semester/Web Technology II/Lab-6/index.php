<?php
// 6. Write a PHP program to check palindrome number.
$number = 12321;
$temp = $number;
$reverse = 0;

while ($temp > 0) {
    $remainder = $temp % 10;
    $reverse = $reverse * 10 + $remainder;

    $temp = (int)($temp / 10);
}

if ($reverse == $number) {
    echo "$number is a Palindrome number\n";
} else {
    echo "$number is not a Palindrome number\n";
}
?>