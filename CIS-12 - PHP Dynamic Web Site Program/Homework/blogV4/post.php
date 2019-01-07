<?php

if( isset($_GET['username']) &&
    isset($_GET['title']) &&
    isset($_GET['body']) ) {
    
    $username   = $_GET['username'];
    $title      = $_GET['title'];
    $body       = $_GET['body'];
    
    print("this is my username: " . $username . "<br/>");
    print("this is my title: " . $title . "<br/>");
    print("this is my body: " . $body . "<br/>");
    
    insertPost($username, $title, $body);
}

function insertPost ($username, $title, $body) {
    mysql_connect('localhost', 'root', 'root');
    mysql_select_db('blog');
    $query = "INSERT INTO posts (username,title,body) VALUES ('$username','$title','$body')";
    $result = mysql_query($query);
    if($result == false) {
        print("query failed: " . $query);
        print("error: " . mysql_error());
    }
}
?>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Make A Post</title>
        <link rel="stylesheet" type="text/css" href="css/style.css">
    </head>
    <body>
        <div id="stylized" class="myform">
            <form id="form" name="form" method="get" action="post.php">
                <h1>Make a Post</h1>
                <p>Here is where you can make a blog post.</p>
                
                <label>Username
                    <span class="small">Add your username</span>
                </label><input type="text" name="username">                
                <label>Title
                    <span class="small">Add your title</span>
                </label><input type="text" name="title">
                <label>Body
                    <span class="small">Add your Body</span>
                </label><textarea name="body"></textarea>
                
                <button type="submit" value="post">Post</button>
                <div class="spacer"></div>
        </form>
    </body>
</html>