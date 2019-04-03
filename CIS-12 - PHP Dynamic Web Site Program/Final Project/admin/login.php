<?php

require_once '../classes/View.php';
require_once '../classes/session.php';

if( isset($_GET['userName']) && isset($_GET['password']) )
{
    $userName   = $_GET['userName'];
    $password   = $_GET['password'];
      

    $user = new Database();
    $result = $user->userLogin($userName, $password);

    if($result == false) {
        $login_failed = true;
        header("location: admin.php");
    } else {
        Session::login($userName);
        header("location: admin.php");
    }
}
?>
