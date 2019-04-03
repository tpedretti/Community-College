<?php
    require_once '../classes/View.php';
    require_once '../classes/Session.php';
    
    
    Session::start();
    $view = new View();    
    
    if(Session::isLoggedIn() == false) {
        print $view->userLogin();
    }
    else {
        require_once 'adminHeader.php';
        
        print $view->adminHome();
        
        require_once 'adminFooter.html';
    }
    
?>
