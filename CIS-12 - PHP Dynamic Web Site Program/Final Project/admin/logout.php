<?php
    require_once '../classes/session.php';
    Session::logout();
    header("location: admin.php");
?>
