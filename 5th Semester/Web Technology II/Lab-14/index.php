<?php
// 14. Remove specific element by value from an array in PHP

function removeElement(&$array, $value) {
    $key = array_search($value, $array);
    if ($key !== false) {
        unset($array[$key]);
        // Reindex the array to maintain numeric keys
        $array = array_values($array);
    }
}

$fruits = ["apple", "banana", "cherry"];
print_r($fruits);

removeElement($fruits, "banana");
print_r($fruits);

echo "\nProgrammed by Milan Bairagi...";
?>