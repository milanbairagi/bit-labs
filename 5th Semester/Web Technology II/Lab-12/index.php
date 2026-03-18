<?php
// 12. Write a PHP program to reverse the string

function reverseString($str) {
    $reversed = '';
    for ($i = strlen($str) - 1; $i >= 0; $i--) {
        $reversed .= $str[$i];
    }
    return $reversed;
}

$string = "abcdefghij";
$reversedString = reverseString($string);

echo "Original String: $string\n";
echo "Reversed String: $reversedString\n";

echo "\nProgrammed by Milan Bairagi...";
?>