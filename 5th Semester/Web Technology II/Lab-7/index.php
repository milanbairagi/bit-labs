<?php
// 7. Write a PHP program to print Fibonacci series without using recursion.

function fib_series($n) {
    $a = 0;
    $b = 1;

    echo "Fibonacci Series: ";

    for ($i = 0; $i < $n; $i++) {
        echo "$a ";
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
    }
} 

$num = 10;
fib_series($num);