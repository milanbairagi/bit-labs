<!-- 5. Write a PHP program to check Armstrong number. -->
<?php
$number = 153;

$temp = $number;
$digits = strlen((string)$number);
$sum = 0;

while ($temp > 0) {
    $digit = $temp % 10;
    $sum += pow($digit, $digits);
    $temp = (int)($temp / 10);
}

if ($sum == $number) {
    echo "$number is an Armstrong number\n";
} else {
    echo "$number is not an Armstrong number\n";
}
?>
