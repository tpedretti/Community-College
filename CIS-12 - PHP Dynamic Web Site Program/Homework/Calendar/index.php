<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" type="text/css" href="style.css">
        <title></title>
    </head>
    <style>
        h1, h2, p {
            text-align:center;
            color:white;
        }
        
        h3 {
            color:red;
            background-color:white;
        }
        
        body {
            background-color:black;
        }
        
        table {
            width:50%;
            padding:10px;
            top:150px;
            margin-left:auto; 
            margin-right:auto;
            border:1px solid white;
            text-align:center;
        }
        
        td {
            padding:10px;
            border:1px solid red;
        }
    </style>
    
    <body>
        
        <?php
        
        date_default_timezone_set('America/Los_Angeles');
        
        $month = date('n');
        
        if(isset($_GET['month'])) {
            $month = $_GET['month'];
            }
        $temp = mktime(0, 0, 0, $month, 1, date('Y'));
        
        echo '<h1>' . date('F, Y', $temp) . '</h1>';
        
        ?>
        
        <table>
            <thread>
            <?php
            $daysOfTheWeek = array('Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat');
            
            echo '<tr>';
            
            for($i = 0; $i < count($daysOfTheWeek); $i++) {
                echo '<td>' . '<h2>' . $daysOfTheWeek[$i] .'</h2>' . '</td>'; 
                
                }
                
                echo '</tr>';
                ?>
            </thread>
            
            <tbody>
                <?php                
                //First date of the month
                $temp = mktime(0, 0, 0, $month, 1, date('Y'));
                //echo 'TIME: ' . date('F j, Y, g:i a', $temp);                
                $firstDayOfTheWeek = date('w', $temp);                
                //echo 'Now: ' . $firstDayOfTheWeek;
                
                //Last date of the month                
                $temp2 = mktime(0, 0, 0, $month + 1, 0, date('Y'));                                
                $lastDayOfTheMonth = date('j', $temp2);
                
                echo '<tr>';
                for($i = 0; $i < $firstDayOfTheWeek; $i++) {
                    echo '<td>' . '' . '</td>';
                }
                
                $counter = $firstDayOfTheWeek;
                
                for($i = 1; $i < $lastDayOfTheMonth + 1; $i++) {
                    if($i == date('w') && $month == date('n')) {
                        echo '<td>' . '<h3>' . $i .'</h3>' . '</td>';
                    }
                    else {
                        echo '<td>' . '<p>' . $i .'</p>' . '</td>';
                    }     
                    $counter++;
                    if($counter % 7 == 0) {
                        echo '</tr><tr>';
                    }
                }
                
                echo '</tr>';                
                ?>
            </tbody>
        </table>
        
        <?php
        $month = $month + 1;
        
        echo "<a href=\"index.php?month=$month\"><h2>Next Month</h2></a>";      
        ?>
    </body>
</html>