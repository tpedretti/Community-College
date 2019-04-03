<?php
    require_once 'classes/View.php';
    require_once 'header.html';
    
    $view = new View();
    
    $html = $view->createTabs();    
    print $html;
    
    print $view->buttonPostThread();
        
    require_once 'footer.html';
    
?>