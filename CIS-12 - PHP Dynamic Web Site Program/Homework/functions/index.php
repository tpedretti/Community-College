<?php

function sum($a, $b) {
    $number = func_num_args();
    $sum = 0;
    
    for($i = 0; $i < $number; $i++) {
        $sum += func_get_arg($i);
    }
    
    return $sum;
}

$s = sum(1, 4, 2, 5, 7, 23, 66, 234, 34);

print("Sum of all #'s : $s");

?>