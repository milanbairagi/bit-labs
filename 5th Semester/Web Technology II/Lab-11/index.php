<?php
// 11. Write a PHP program to illustrate string patterns using ReGex


$email = "milan@gmail.com";
$pattern = '/^[\w._+]+@[\w.-]+\.[\w]{2,}$/';
    
if (preg_match($pattern, $email)) {
    echo "$email is a valid email address\n";
} else {
    echo "$email is an invalid email address\n";
}
?>