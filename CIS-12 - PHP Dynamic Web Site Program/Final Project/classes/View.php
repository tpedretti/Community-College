 <?php

require_once 'Database.php';

class View {
    private $db;
    
    function __construct() {
        $this->db = new Database();
    }    
    function createTabs() {
        $content = "";
        
        //Top AD
        $content .= '<div style="position:fixed; right:20%; top:50px;">
            <script type="text/javascript"><!--
            google_ad_client = "ca-pub-6884744145076755";
            /* LOLLFG Top AD */
            google_ad_slot = "1701710916";
            google_ad_width = 728;
            google_ad_height = 90;
            //-->
            </script>            
            <script type="text/javascript"
            src="http://pagead2.googlesyndication.com/pagead/show_ads.js">
            </script>
            </div>';
        
        $content .= "<h1>People LFG!</h1>
            <ul id=\"tabs\" class=\"nav nav-tabs\" data-tabs=\"tabs\">
                <li class=\"active\"><a href=\"#na\" data-toggle=\"tab\">NA</a></li>                
                <li><a href=\"#eu\" data-toggle=\"tab\">EU</a></li>
            </ul>

             <div class=\"tab-content\">";
        $content .= View::createMainViwNA();
        $content .= View::createMainViwEU();
        
        return $content;
    }
    function createMainViwNA() {
        $content = "";
        
        if(($posts = $this->db->getUserPostsNA()) && mysql_num_rows($posts) > 0) {
            $content .= "<div class=\"tab-pane active\" id=\"na\">";            
            $content .= "<table class=\"table\">";           
            $content .= "<thread>";
            $content .= "<tr>";
            $content .= "<th>Summoner Name</td>";
            $content .= "<th>Game Type</td>";
            $content .= "<th>User Comment</td>";
            $content .= "<th>Time Created</td>";
            $content .= "</tr>";
            $content .= "</thead>";
            
            while($row = mysql_fetch_assoc($posts)) {
                $content .= "<tbody>";
                $content .= "<tr>";
                $content .= "<td>" . $row['summonerName']   . "</td>";
                $content .= "<td>" . $row['gameType']       . "</td>";
                $content .= "<td>" . $row['userComments']   . "</td>";                
                $time = strtotime($row['timeCreated']);                
                $content .="<td>" . View::timeConverter($time) . "</td>";
                $content .= "</tr>";
                $content .= "</tbody>";
            }
            
            $content .= "</table>";
            $content .= "</div>";
            
        return $content;
       }
       else
           return FALSE;
    }    
    function createMainViwEU() {
        $content = "";
        
        if(($posts = $this->db->getUserPostsEU()) && mysql_num_rows($posts) > 0) {
            $content .= "<div class=\"tab-pane\" id=\"eu\">";            
            $content .= "<table class=\"table\">";           
            $content .= "<thread>";
            $content .= "<tr>";
            $content .= "<th>Summoner Name</td>";
            $content .= "<th>Game Type</td>";
            $content .= "<th>User Comment</td>";
            $content .= "<th>Time Created</td>";
            $content .= "</tr>";
            $content .= "</thead>";
            
            while($row = mysql_fetch_assoc($posts)) {
                $content .= "<tbody>";
                $content .= "<tr>";
                $content .= "<td>" . $row['summonerName']   . "</td>";
                $content .= "<td>" . $row['gameType']       . "</td>";
                $content .= "<td>" . $row['userComments']   . "</td>";
                $time = strtotime($row['timeCreated']);                
                $content .="<td>" . View::timeConverter($time) . "</td>";
                $content .= "</tr>";
                $content .= "</tbody>";
            }
            
            $content .= "</table>";
            $content .= "</div>";
            
        return $content;
       }
       else
           return FALSE;
    }
    function makePost() {
        
        $userLoc = array("NA"=>"NA", "EU"=>"EU");
        $gameType = array("DuoNormal"=>"Duo-Normal", "DuoRanked"=>"Duo-Ranked", "Normal5v5"=>"Normal 5v5",
                          "Ranked5v5"=>"Ranked 5v5", "Normal3v3"=>"Normal 3v3", "Ranked3v3"=>"Ranked 3v3",
                          "ARAM"=>"ARAM");
        
        
        $content = '<div style="width: 50%; margin: 0px auto; padding-top: 100px;">';
        $content = '<h1>Make a Group!</h1>';
        $content .= '<br>';
        $content .= '<br>';
        $content .= '<br>';
        
        
        $content .= '<form id="postForm" method="get" accept-charset="utf-8" style="margin:0 auto;" action="posting.php">';
        
        $content .= '<label>Username';
        $content .= '<span class="small">Add your Summoner Name</span>';
        $content .= '</label>';
        $content .= '<input id="input_title" type="text" name="summonerName" value="Summoner Name" size="128" />';
        $content .= '<br>';
        $content .= '<br>';
        $content .= '<br>';
        
        
        $content .= '<label>User Regain';
        $content .= '<span class="small">Select your Regain</span>';
        $content .= '</label>';
        $content .= '<select name="loc">';
        $content .= '<option value="0">Choose One</option>';
        foreach($userLoc as $key => $value)
            $content .= '<option value="'. $key .'">'. $value . '</option>';        
        $content .= '</select>';
        $content .= '<br>';
        $content .= '<br>';
        $content .= '<br>';
        
        $content .= '<label>Game Type';
        $content .= '<span class="small">Select a Game Type</span>';
        $content .= '</label>';
        $content .= '<select name="gameType">';
        $content .= '<option value="0">Choose One</option>';
        foreach($gameType as $key => $value)
            $content .= '<option value="'. $key .'">'. $value . '</option>';
        $content .= '</select>';
        $content .= '<br>';   
        $content .= '<br>';
        $content .= '<br>';
        
        $content .= '<label>User Comment';
        $content .= '<span class="small">Add a User Comment</span>';
        $content .= '</label>';
        $content .= '<textarea name="userComments" rows="8" cols="88">Message</textarea>';
        $content .= '<br>';
        
        $content .= '<button type="submit" value="Post">Make Post</button>';
        //$content .= '<input type="submit" id="submit_box" value="Post the Group" />';
        $content .= '</form>';
        $content .= '</div>';

        return $content;
    }
    function buttonPostThread() {
        return "<form id=\"createPostID\" action=\"createPost.php\">
                    <input type=\"submit\" value=\"Make a Post\">
                </form>";
    }
    function timeConverter($time) {

    $time = time() - $time; // to get the time since that moment

    $tokens = array (
        31536000 => 'year',
        2592000 => 'month',
        604800 => 'week',
        86400 => 'day',
        3600 => 'hour',
        60 => 'minute',
        1 => 'second'
    );

    foreach ($tokens as $unit => $text) {
        if ($time < $unit) continue;
        $numberOfUnits = floor($time / $unit);
        return $numberOfUnits.' '.$text.(($numberOfUnits>1)?'s':'');
    }

}
    function userLogin() {
        $content = "";
        
        $content .= '<!DOCTYPE html>
                        <html lang="en">
                          <head>
                            <meta charset="utf-8">
                            <title>Sign in &middot; Twitter Bootstrap</title>
                            <meta name="viewport" content="width=device-width, initial-scale=1.0">
                            <meta name="description" content="">
                            <meta name="author" content="">

                            <!-- Le styles -->
                            <link href="../media/css/bootstrap.css" rel="stylesheet">
                            <style type="text/css">
                              body {
                                padding-top: 40px;
                                padding-bottom: 40px;
                                background-color: #f5f5f5;
                              }

                              .form-signin {
                                max-width: 300px;
                                padding: 19px 29px 29px;
                                margin: 0 auto 20px;
                                background-color: #fff;
                                border: 1px solid #e5e5e5;
                                -webkit-border-radius: 5px;
                                   -moz-border-radius: 5px;
                                        border-radius: 5px;
                                -webkit-box-shadow: 0 1px 2px rgba(0,0,0,.05);
                                   -moz-box-shadow: 0 1px 2px rgba(0,0,0,.05);
                                        box-shadow: 0 1px 2px rgba(0,0,0,.05);
                              }
                              .form-signin .form-signin-heading,
                              .form-signin .checkbox {
                                margin-bottom: 10px;
                              }
                              .form-signin input[type="text"],
                              .form-signin input[type="password"] {
                                font-size: 16px;
                                height: auto;
                                margin-bottom: 15px;
                                padding: 7px 9px;
                              }

                            </style>
                            <link href="media/css/bootstrap-responsive.css" rel="stylesheet">

                            <!-- HTML5 shim, for IE6-8 support of HTML5 elements -->
                            <!--[if lt IE 9]>
                              <script src="../assets/js/html5shiv.js"></script>
                            <![endif]-->

                            <!-- Fav and touch icons -->
                            <link rel="apple-touch-icon-precomposed" sizes="144x144" href="../assets/ico/apple-touch-icon-144-precomposed.png">
                            <link rel="apple-touch-icon-precomposed" sizes="114x114" href="../assets/ico/apple-touch-icon-114-precomposed.png">
                              <link rel="apple-touch-icon-precomposed" sizes="72x72" href="../assets/ico/apple-touch-icon-72-precomposed.png">
                                            <link rel="apple-touch-icon-precomposed" href="../assets/ico/apple-touch-icon-57-precomposed.png">
                                                           <link rel="shortcut icon" href="../assets/ico/favicon.png">
                          </head>

                          <body>

                            <div class="container">

                              <form class="form-signin" method="get" action="login.php">
                                <h2 class="form-signin-heading">Please sign in</h2>
                                <input type="text" name="userName" class="input-block-level" placeholder="User Name">
                                <input type="password" name="password" class="input-block-level" placeholder="Password">
                                <label class="checkbox">
                                  <input type="checkbox" value="remember-me"> Remember me
                                </label>
                                <button class="btn btn-large btn-primary" type="submit">Sign in</button>
                              </form>
                              
                            <?php if(isset($login_failed)) { ?>
                            <div class="alert alert-error" style="width: 300px;margin-left: auto;margin-right: auto;">
                                Login Error!
                            </div>
                            <?php } ?>

                            </div> <!-- /container -->

                            <!-- Le javascript
                            ================================================== -->
                            <!-- Placed at the end of the document so the pages load faster -->
                            <script src="../assets/js/jquery.js"></script>
                            <script src="../assets/js/bootstrap-transition.js"></script>
                            <script src="../assets/js/bootstrap-alert.js"></script>
                            <script src="../assets/js/bootstrap-modal.js"></script>
                            <script src="../assets/js/bootstrap-dropdown.js"></script>
                            <script src="../assets/js/bootstrap-scrollspy.js"></script>
                            <script src="../assets/js/bootstrap-tab.js"></script>
                            <script src="../assets/js/bootstrap-tooltip.js"></script>
                            <script src="../assets/js/bootstrap-popover.js"></script>
                            <script src="../assets/js/bootstrap-button.js"></script>
                            <script src="../assets/js/bootstrap-collapse.js"></script>
                            <script src="../assets/js/bootstrap-carousel.js"></script>
                            <script src="../assets/js/bootstrap-typeahead.js"></script>

                          </body>
                        </html>';
        return $content;
    }
    
    function adminHome() {
        return View::createAdminTabs();
    }
    function createAdminTabs() {
        $content = "";
        
        $content .= "<h1>Admin Control Panel</h1>
            <ul id=\"tabs\" class=\"nav nav-tabs\" data-tabs=\"tabs\">
                <li class=\"active\"><a href=\"#na\" data-toggle=\"tab\">NA</a></li>                
                <li><a href=\"#eu\" data-toggle=\"tab\">EU</a></li>
            </ul>

             <div class=\"tab-content\">";
        $content .= View::createAdminViewNA();
        $content .= View::createAdminViewEU();
        
        return $content;
    }
    function createAdminViewNA() {
        $content = "";
        
        $content .= '<form action="deleteNA.php" method="post">';
        
        if(($posts = $this->db->adminUserPostsNA()) && mysql_num_rows($posts) > 0) {
            $content .= "<div class=\"tab-pane active\" id=\"na\">";            
            $content .= "<table class=\"table\">";           
            $content .= "<thread>";
            $content .= "<tr>";
            $content .= "<th>Database ID</td>";
            $content .= "<th>Summoner Name</td>";
            $content .= "<th>Game Type</td>";
            $content .= "<th>User Comment</td>";
            $content .= "<th>Time Created</td>";
            $content .= "<th>Action</td>";
            $content .= "</tr>";
            $content .= "</thead>";
            
            while($row = mysql_fetch_assoc($posts)) {
                $content .= "<tbody>";
                $content .= "<tr>";
                $content .= "<td>" . $row['dbID'] . "</td>";
                $content .= "<td>" . $row['summonerName']   . "</td>";
                $content .= "<td>" . $row['gameType']       . "</td>";
                $content .= "<td>" . $row['userComments']   . "</td>";
                
                $time = strtotime($row['timeCreated']);                
                $content .= "<td>" . View::timeConverter($time) . "</td>";
                
                $content .= '<td><input name="checkbox['. $row['dbID'] .']" type="checkbox"></td>';
                //$content .= '<td> <input name="checkbox[' . $row['dbID'] . ']" type="checkbox"> </td>';
                
                $content .= "</tr>";
                $content .= "</tbody>";
            }
            
            $content .= "<td> </td>";
            $content .= "<td> </td>";
            $content .= "<td> </td>";
            $content .= "<td> </td>";
            $content .= "<td> </td>";
            $content .= '<td><input name="delete" type="submit" id="delete" value="Delete"></td>';
            //$content .= '<td><input name="delete" type="submit" id="delete" method="post" value="Delete Files"></td>';
            $content .= "</table>";
            $content .= "</form>";
            $content .= "</div>";
            
            
            
            
        return $content;
       }
       else
           return FALSE;
    }
    function createAdminViewEU() {
        $content = "";
        
        if(($posts = $this->db->adminUserPostsEU()) && mysql_num_rows($posts) > 0) {
            $content .= "<div class=\"tab-pane active\" id=\"eu\">";            
            $content .= "<table class=\"table\">";           
            $content .= "<thread>";
            $content .= "<tr>";
            $content .= "<th>Database ID</td>";
            $content .= "<th>Summoner Name</td>";
            $content .= "<th>Game Type</td>";
            $content .= "<th>User Comment</td>";
            $content .= "<th>Time Created</td>";
            $content .= "<th>Action</td>";
            $content .= "</tr>";
            $content .= "</thead>";
            
            while($row = mysql_fetch_assoc($posts)) {
                $content .= "<tbody>";
                $content .= "<tr>";
                $content .= "<td>" . $row['dbID'] . "</td>";
                $content .= "<td>" . $row['summonerName']   . "</td>";
                $content .= "<td>" . $row['gameType']       . "</td>";
                $content .= "<td>" . $row['userComments']   . "</td>";                
                $time = strtotime($row['timeCreated']);                
                $content .="<td>" . View::timeConverter($time) . "</td>";
                $content .= "</tr>";
                $content .= "</tbody>";
            }
            
            $content .= "</table>";
            $content .= "</div>";
            
        return $content;
       }
       else
           return FALSE;
    }
    function removePostNA($dbID) {
        
    }
}

?>
