<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title></title>
        <style>
            body{
                font-family:"Lucida Grande", "Lucida Sans Unicode", Verdana, Arial, Helvetica, sans-serif;
                font-size:12px;
            }
            p, h1, form, button{
                border:0;
                margin:0;
                padding:0;
                margin-left:auto;
                margin-right:auto;
                width:70%;
            }
            .spacer{clear:both; height:1px;}
            /* ----------- My Form ----------- */
            .myform{
                margin:0 auto;
                width:400px;
                padding:14px;
            }
            
            /* ----------- stylized ----------- */
            #stylized{
                border:solid 2px #b7ddf2;
                background:#ebf4fb;
            }
            #stylized h1 {
                font-size:14px;
                font-weight:bold;
            }
            #stylized p{
                font-size:11px;
                color:#666666;
                margin-bottom:20px;
                border-bottom:solid 1px #b7ddf2;
                padding-bottom:10px;
                text-align: center;
            }
            #stylized label{
                display:block;
                font-weight:bold;
                text-align:right;
                width:140px;
                float:left;
            }
            
            #stylized input{
                font-size:12px;
                padding:4px 2px;
                border:solid 1px #aacfe4;
                width:200px;
                margin:2px 0px 5px 40px;
            }
            #stylized select {
                font-size:12px;
                padding:0px 0px;
                border:solid 1px #aacfe4;
                width:100px;
                margin:2px 0px 10px 95px;
            }
            #stylized button{
                clear:both;
                margin-left:250px;
                width:125px;
                height:31px;
                text-align:center;
                line-height:31px;
                color:#FFFFFF;
                font-size:11px;
                font-weight:bold;
            }
        </style>
        
    </head>
    <body>
        <div id="stylized" class="myform">
            <form method="get" action="index.php">
                <label>Number #1</label> <input type="text" name="a" /> </br>
                <label>Number #2</label> <input type="text" name="b" /> </br>
                <select name="math">
                    <option value="sum">Add</option>
                    <option value="sub">Subtraction</option>
                    <option value="times">Multi</option>
                    <option value="div">Div</option>
                </select>
                <input type="submit" /> 
            </form>
        <p>
        <?php
        //The Vars!
        $userVarA = $_REQUEST['a'];
        $userVarB = $_REQUEST['b'];
        $userOption = $_REQUEST['math'];
        
        //Where the mathzz is done
        $sum = $userVarA + $userVarB;
        $sub = $userVarA - $userVarB;
        $multi = $userVarA * $userVarB;
        $div = $userVarA / $userVarB;
        
        //Oh look if and else if maybe a else too!
        if($userOption == "sum")
            echo $sum;
        else if($userOption == "sub")
            echo $sub;
        else if($userOption == "times")
            echo $multi;
        else if($userOption == "div")
            echo $div;
        else
            echo "Enter in numbers for the MATHZ!!!";        
        ?>
        </p>
        </div>
    </body>
</html>
