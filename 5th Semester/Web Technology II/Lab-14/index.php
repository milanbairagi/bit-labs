<?php
// 14. Remove specific element by value from an array in PHP

function removeElement(&$array, $value) {
    for ($i = 0; $i < count($array); $i++) {
        if ($array[$i] == $value) {
            array_splice($array, $i, 1);
            return;
        }
    }
}

$fruits = ["apple", "banana", "cherry", "date", "banana"];
print_r($fruits);

removeElement($fruits, "banana");
print_r($fruits);