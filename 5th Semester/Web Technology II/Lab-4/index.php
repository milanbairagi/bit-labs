<!-- 4. Write a PHP program to print factorial of a number. -->
<?php
$number = 6;

function factorial($n) {
    if ($n == 0 || $n == 1) return 1;
    return $n * factorial($n - 1);
}

echo "Factorial of $number = " . factorial($number) . "\n";
?>
