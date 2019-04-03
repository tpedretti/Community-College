<?php
require_once 'classes/View.php';
require_once 'header.html';

$view = new View();

print $view->makePost();

require_once 'footer.html';

?>