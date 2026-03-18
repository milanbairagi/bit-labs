<?php
// 13. Write a PHP program to count the words in the string
function countWords($str) {
    $num_words = 0;
    for ($i = 0; $i < strlen($str); $i++) {
        if ($str[$i] == ' ' && $i > 0 && $str[$i - 1] != ' ') {
            $num_words++;
        }
    }
    echo "Number of words: " . ($num_words + 1) . "\n";
}

$string = "Hello World! This is a PHP";
echo "String: $string\n";
countWords($string);

echo "\nProgrammed by Milan Bairagi...";
?>