<?php
require_once '../classes/View.php';
require_once '../classes/Database.php';

if(isset($_POST['delete'])){//check to see if the delete button has been pressed

   if(isset($_POST['checkbox'])){ //check to see if any boxes have been checked
        $num = 0;//used to count the number of rows that were deleted
        $box = $_POST['checkbox'];
        
        $sqldel = new Database();
        
        while (list ($key,$dbID) = @each ($box)) { //loop through all the checkboxes
              $num++;
              $sqldel->removePostNA($dbID);
              //$sqldel = "DELETE FROM logins WHERE dbID='$val'";//delete any that match id
              //$resdel = mysql_query($sqldel);//send the query to mysql
        }
        //print the logs that were deleted
        echo"$num record(s) have been deleted.";
   }
   else{//no boxes checked
   echo "No records selected.";
   }
}

//header("location: admin.php");
?>
