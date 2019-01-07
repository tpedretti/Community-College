<?php
session_start();

    $resource = mysql_connect("localhost","root","root");

    if( $resource == false ) {
        print("failed to connect to mysql");
        exit();
    }

    $result = mysql_select_db("login",$resource);

    if( $result == false ) {
        print("failed to select database!");
        exit();
    }

    $result = mysql_query("select * from users;");

    while ( $row = mysql_fetch_assoc($result)  )
    {
      //  var_dump($row);
    }

    $error = mysql_error();

    $email = "";
    $password = "";
    
    if( isset($_GET['email']) ) {
        $email = $_GET['email'];
    }
    
    if( isset( $_GET['password']) ) {
       $password   = $_GET['password'];
    }   
    
    $login_result = checklogin($email, $password);

    if( $login_result == true ) {
        print("<br> email and password is correct!");
        $_SESSION['login'] = true;        
    } else {
        print("<br> login failed!");    
    }

    function checklogin ($email, $password)
    {
        $hash = $password . "THIS IS SOME STRING";        
        $hash = sha1($hash);        
        
        $result = 

        mysql_query(

        "select * from users where email='$email' and password='$hash'"

        );

        $row = mysql_fetch_assoc($result);

        if( $row == false ) {
            return false;
        }

        return true;
    }

if(isset($_SESSION['login']) && $_SESSION['login'] == true)
{
    header("LOCATION: home.php");
    return;
}

?>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Login</title>        
        <style>            
            h4 {
                margin: 0px;
                padding-bottom: 10px;
            }
            
            form {
                display: block;
                margin-left: auto;
                margin-right: auto;
                width: 200px;
                height: 150px;
                padding: 25px;
                box-shadow: 0px 0px 20px #cccccc; 
                border-style: solid;
                border-color: #cccccc;
                border-width: 1px;
            }
            
            label {
                display: block;
            }
            
            input {                
                display: block;       
                margin-bottom: 10px;
            }
            
        </style>
        
    </head>
    <body>
        
    <form method="get" action="index.php">
        <h4>Login</h4>
        <label>email</label><input type="text" name="email">
        <label>password</label><input type="password" name="password">    
        <input type="submit" value="login">
    </form>

    </body>
</html>
