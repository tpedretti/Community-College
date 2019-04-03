<?php
require_once 'config.inc.php';

class Database {
    private $db;
    
    function __construct() {
        set_error_handler(array($this,'errorHandler'));
        $this->db = mysql_connect(DB_HOSTNAME, DB_USERNAME, DB_PASSWORD);
        mysql_select_db(DB_NAME, $this->db);
    }
    function errorHandler($errno, $errstr) {
            switch ($errno){
                case E_WARNING:
                            echo '<b>There has been an error with the MySQL database connection. '.
                                     'Please, make sure the config file is OK.</b>';
                            die(); 
                default:
                    return false;
            }
    }
    function getUserPostsNA() {
        $query = "SELECT * from usersNA order by timeCreated desc";        
        return mysql_query($query);
    }
    function getUserPostsEU() {
        $query = "SELECT * from usersEU order by timeCreated desc";        
        return mysql_query($query);
    }
    function saveUserPosts($summonerName, $gameType, $userComments, $loc) {
        if($loc == "NA") {
            $query = "INSERT INTO usersNA (summonerName, gameType, userComments) VALUES ('$summonerName', '$gameType', '$userComments')";
            $errorCheck = mysql_query($query);
            
            if($errorCheck  == false) {
                print("query failed: " . $query);
                print("error: " . mysql_error());
                print("Please report this to an Admin.");
            }  
        }
        else if($loc == "EU") {
            $query = "INSERT INTO usersEU (summonerName, gameType, userComments) VALUES ('$summonerName', '$gameType', '$userComments')";
            $errorCheck = mysql_query($query);
            
            if($errorCheck  == false) {
                print("query failed: " . $query);
                print("error: " . mysql_error());
                print("Please report this to an Admin.");
            }  
        }
        else {
            print "What did you do...";
        }
    }
    function userLogin($userName, $password) {
        $hash = md5($password);
        $query = "SELECT * from users where userName='$userName' and password='$hash'";
        $result = mysql_query($query);
        $row = mysql_fetch_assoc($result);
        
        if($row == FALSE)
            return FALSE;
        
        return true;        
    }
    
    function adminUserPostsNA() {
        $query = "SELECT * from usersNA order by timeCreated desc";
        return mysql_query($query);
    }
    function adminUserPostsEU() {
        $query = "SELECT * from usersEU order by timeCreated desc";        
        return mysql_query($query);
    }
    function removePostNA($dbID) {
        $query = "DELETE from usersNA WHERE dbID='$dbID'";
        return mysql_query($query);
    }
    
}

?>