<?php
// 7. Write a PHP program to print Fibonacci series without using recursion and using recursion.

function fib_series_without_recursion($n) {
    $a = 0;
    $b = 1;
    for ($i = 0; $i < $n; $i++) {
        echo "$a ";
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
    }
}

function fib_series_with_recursion($n) {
    if ($n <= 1) return $n;
    return fib_series_with_recursion($n - 1) + fib_series_with_recursion($n - 2);
}

$num = 10;

echo "Fibonacci Series without Recursion: ";
fib_series_without_recursion($num);

echo "\nFibonacci Series with Recursion: ";
for ($i = 0; $i < $num; $i++) {
    echo fib_series_with_recursion($i) . " ";
}

echo "\nProgrammed by Milan Bairagi...";
?>