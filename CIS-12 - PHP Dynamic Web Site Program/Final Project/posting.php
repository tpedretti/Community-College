<?php

require_once 'classes/Database.php';

if( isset($_GET['summonerName']) &&
    isset($_GET['loc']) &&
    isset($_GET['gameType']) &&
    isset($_GET['userComments'])) {
    
    $savePost = new Database();
    
    $summonerName   = $_GET['summonerName'];
    $loc            = $_GET['loc'];    
    $gameType       = $_GET['gameType'];
    $userComments   = $_GET['userComments'];
    
    $savePost->saveUserPosts($summonerName, $gameType, $userComments, $loc);
    
    header("Location: index.php");
    exit;
    
    print("this is my username: " . $summonerName . "<br/>");
    print("this is my username: " . $loc . "<br/>");
    print("this is my body: " . $gameType . "<br/>");   
    print("this is my username: " . $userComments . "<br/>");    
    //saveUserPosts($summonerName, $gameType, $userComments);
}

//function saveUserPosts($summonerName, $gameType, $userComments) {
//    mysql_connect(DB_HOSTNAME, DB_USERNAME, DB_PASSWORD);
//    mysql_select_db(DB_NAME);
//    $query = "INSERT INTO userPosts (summonerName, gameType, userComments) VALUES ('$summonerName', '$gameType', '$userComments')";
//    
//    $result = mysql_query($query);
//    if($result == false) {
//        print("query failed: " . $query);
//        print("error: " . mysql_error());
//    }
//}
?>