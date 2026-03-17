<?php
// 3. Write a PHP program to check prime number.
$number = 29;

function isPrime($n) {
    if ($n < 2) return false;
    for ($i = 2; $i <= sqrt($n); $i++) {
        if ($n % $i == 0) return false;
    }
    return true;
}

if (isPrime($number)) {
    echo "$number is a Prime number\n";
} else {
    echo "$number is not a Prime number\n";
}
?>
