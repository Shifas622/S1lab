<html>
    <head>
        <title>dropdown</title>
        <body>
<?php
    echo"<table border='1'>
                <tr>
                    <th>Select NO:</th>
                    <td><select>";
                            for($i=0;$i<=10;$i++)
                            {
                                echo"<option value='$i'>$i</option>";
                            }
                            echo"</select></td></table>";
                    
?>
</body>