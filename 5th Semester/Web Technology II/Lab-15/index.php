<?php
// 15. Create a class named “Bird”. Also, create two objects pigeon and crow.
// Display their colors, habitats and what they eat.
class Bird {
    public $color;
    public $habitat;
    public $food;

    // public function __construct($color, $habitat, $food) {
    //     $this->color = $color;
    //     $this->habitat = $habitat;
    //     $this->food = $food;
    // }

    // public function __toString() {
    //     return " Color: $this->color \n Habitat: $this->habitat \n Food: $this->food";
    // }

    public function display() {
        echo "Color: " . $this->color . "\n";
        echo "Habitat: " . $this->habitat . "\n";
        echo "Food: " . $this->food . "\n";
    }
}

// $pigeon = new Bird("Gray", "Cities", "Seeds");
// $crow = new Bird("Black", "Forests", "Insects");

$pigeon = new Bird();
$pigeon->color = "Gray";
$pigeon->habitat = "Cities";
$pigeon->food = "Seeds";

$crow = new Bird();
$crow->color = "Black";
$crow->habitat = "Forests";
$crow->food = "Insects";

echo "Pigeon:\n";
// echo $pigeon . "\n\n";
$pigeon->display();

echo "\nCrow:\n";
// echo $crow;
$crow->display();