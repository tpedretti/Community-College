<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Register</title>        
        
        <link href="css/ui-lightness/jquery-ui-1.10.2.custom.css" rel="stylesheet">	
        
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
                height: 200px;
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
    <?php
    
    
    if( isset($_GET['email']) &&
        isset($_GET['confirm_email']) &&
        isset($_GET['password']) )
    {
        $email      = $_GET['email'];
        $confirm    = $_GET['confirm_email'];
        $password   = $_GET['password'];
                
        if( strlen($email) < 3 ) {
            $error_message = "email is too short!";
        }
        else if( filter_var($email, FILTER_VALIDATE_EMAIL) == false ) {
            $error_message = "not a valid email!";
        } 
        else if ( $email !== $confirm ) {
            $error_message = "email's dont match!";
        }
        else if( strlen($password) < 3 ) {
            $error_message = "password is too short!";
        }
        else {            
            if( createUser($email, $password) == false ) {
                $error_message = "create user failed!";
            } else {
                $success_message = "user registered " . $email;
            }
        }
    }
       
    
    
    function createUser($email, $password) {
        $resource = mysql_connect('localhost', 'root', 'root');
        mysql_select_db('login');
        $hash = $password . "THIS IS SOME STRING";        
        $hash = sha1($hash);               
        $result = 
        mysql_query("insert into users values('$email','$hash')",$resource);
        return $result;
    }
    
    
    
    ?>
    
        
    <?php if(isset($error_message)) { ?>    
    <div class="ui-widget">
	<div class="ui-state-error ui-corner-all" style="padding: 0 .7em;">
		<p><span class="ui-icon ui-icon-alert" style="float: left; margin-right: .3em;"></span>
		<strong>Alert:</strong>                
                <?php
                    print($error_message);
                ?>                
                </p>
	</div>
    </div>        
    <?php } ?>
                
    <?php if(isset($success_message)) { ?>
    <div class="ui-widget">
	<div class="ui-state-highlight ui-corner-all" style="margin-top: 20px; padding: 0 .7em;">
		<p><span class="ui-icon ui-icon-info" style="float: left; margin-right: .3em;"></span>
		<strong>Hey!</strong>
                <?php
                    print($success_message);
                ?>
                </p>
	</div>
    </div>
    <?php } ?>
        
        
    <form method="get" action="register.php">
        <h4>Register</h4>
        <label>email</label><input type="text" name="email">
        <label>confirm email</label><input type="text" name="confirm_email">    
        <label>password</label><input type="password" name="password">    
        <input type="submit" value="register">
    </form>
    </body>
</html>