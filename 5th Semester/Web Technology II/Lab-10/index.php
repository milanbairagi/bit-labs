<?php
// 10. Write a PHP program to show the conversion between array and variables.

// --- Array to Variables using extract() ---
$person = [
    "name" => "Milan",
    "age"  => 21,
    "city" => "Kathmandu"
];

echo "=== Array to Variables (extract) ===\n";
extract($person);
echo "Name: $name\n";
echo "Age:  $age\n";
echo "City: $city\n";

// --- Variables to Array using compact() ---
echo "\n=== Variables to Array (compact) ===\n";
$country = "Nepal";
$language = "PHP";
$version  = 8;

$info = compact("country", "language", "version");
print_r($info);
