<?php
// 8. Write a PHP program to reverse given number.

function reverse($n) {
    $rev = 0;
    while ($n > 0) {
        $rem = $n % 10;
        $rev = $rev * 10 + $rem;
        $n = (int) ($n / 10);
    }
    return $rev;
}

$number = 12345;
$reversedNumber = reverse($number);

echo "Original number: $number\n";
echo "Reversed number: $reversedNumber\n";