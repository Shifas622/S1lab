<?php
if (isset($_POST['submit']))
{
    $username=$_POST['username'];
    $password=$_POST['password'];
    include "connection.php";
    $sql="select * from login where username='$username' and password='$password'";
    $result=mysqli_query($con,$sql);
    if(mysqli_num_rows($result)!=1)
    {
        echo"<script>alert('Invalid Username And Password');window.location.href='login.php'</script>";
    }
    else
    {
        echo"<script>window.location.href='admin_dash.php'</script>";
    }
    mysqli_close($con);

}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h2>Login </h2>
    <form action="" method="POST">
        <table border="1">
            <tr>
                <th>username</th>
                <td><input type="text" name="username"></td>
            </tr>

             <tr>
                <th>Passoword</th>
                <td><input type="password" name="password"></td>
            </tr>

            <tr>
                <td colspan="2" align="center"><input type="submit"  name="submit" value="login"></td>
            </tr>
</form>

</body>
</html>