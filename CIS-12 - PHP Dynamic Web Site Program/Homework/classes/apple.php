<?php
function hereisafunction() {
    
}

class apple {
    //put your code here
    public $color;
    protected $color2;
    private $color3;
    
    public function mymethod() {
        $this->color2 = "Some color";
        $this->color3 = "some other color";
    }
}

$a = new apple();

$a->mymethod();

$a->color = "red";



?>
