<?php
// 16. Give an example of parameterized constructor in PHP.
class Person {
    public $name;
    public $age;

    // Parameterized constructor
    public function __construct($name, $age) {
        $this->name = $name;
        $this->age = $age;
    }

    public function display() {
        echo "Name: " . $this->name . "\n";
        echo "Age: " . $this->age . "\n";
    }
}

$person1 = new Person("Milan", 21);
$person2 = new Person("John", 25);

$person1->display();
echo "\n";
$person2->display();
