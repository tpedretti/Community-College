<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Blog</title>
        <link rel="stylesheet" type="text/css" href="css/style.css">
        <style>
            body {
                background-color:gray;
            }            
            #blogbody {
                margin-left: auto;
                margin-right: auto;
                width: 600px;
                height: 970px;
                background-color: white;
                box-shadow: 0px 0px 20px black;
            }
            .post {
                display: block;
                background-color: #eeeeee;
                margin: 10px;
                padding: 10px;
            }
            .comment {
                display: block;
                background-color: #ccff66;
            }
            .comment h1 {
                text-align: right;
            }
            .comment p {
                text-align: right;
            }
        </style>
    </head>    
    <body>        
        <div id="blogbody">
        <?php           
        $page = 0;        
        if( isset($_GET["page"]) ) {
            $page = $_GET["page"];
        }
        
        if($page < 0) $page = 0;
        
        $index = $page * 10;
        
        $link = mysql_connect('localhost','root','root');
        
        mysql_select_db('blog',$link);
                
        $result = mysql_query("select * from posts order by created desc Limit $index,10");
        
        while ( $row = mysql_fetch_assoc($result) ) {
            $id         = $row["id"];          
            $title      = $row["title"];
            $body       = $row["body"];
            $created    = $row["created"];
            $username   = $row["username"];
            
            print("<div class=\"post\">");
            print("<h1>" . $title . "</h1>" );
            print("<p>" . $body . "</p>");
            print("<h5>Crated on:" . $created);
            print("</br>Created by: " . $username . "</h5>");
            print("<a href= \" comments.php?id=$id \">Comment</a> ");
            print("</div>");
            
            $comments_query = "select * from comments where post=$id";
            $comments_result = mysql_query($comments_query);
            
            while($comment = mysql_fetch_assoc($comments_result)) {
                $title      = $comment["title"];
                $body       = $comment["body"];
                $created    = strtotime($comment["created"]); //
                $username   = $comment["username"];
                
                print("<div class=\"comment\">");
                print("<h1>" . $title . "</h1>" );
                print("<p>" . $body . "</p>");
                print("<h5>Crated on:" . $created);
                print("</br>Created by: " . $username . "</h5>");
                print("</div>");
            }
            
        }                 
        ?>
            <div id="lowerbuttons">
                <a href="index.php?page=<?php print($page-1); ?>"><button>Prev Page</button></a>
                <a href="index.php?page=<?php print($page+1); ?>"><button>Next Page</button></a> 
                <a href="post.php"><button>Post<button></a>
            </div> 
        </div>
    </body>
</html>