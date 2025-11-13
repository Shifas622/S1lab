<?php
if (isset($_POST["submit"])) {
    $name = $_POST["name"];
    $rollno = $_POST["roll"];
    $address = $_POST["address"];
    $phno = $_POST["phno"];
    $username = $_POST["username"];
    $password = $_POST["password"];

    include("connection.php");


    $hashed_password = password_hash($password, PASSWORD_DEFAULT);

    $sql = "INSERT INTO stud (name, rollno, address, phno, username, password)
            VALUES ('$name', '$rollno', '$address', '$phno', '$username', '$password')";

    $result = mysqli_query($con, $sql);

  
    if ($result) {
        echo "<script>alert('Registered Successfully'); window.location.href='admin_dash.php';</script>";
    } else {
        echo "<script>alert('Error occurred while registering'); window.location.href='student_registration.php';</script>";
    }
}
?>
<html>
<head>
    <title>Student Registration</title>
    <style>
        *{margin:0;padding:0;box-sizing:border-box;font-family:"Poppins",sans-serif;}
        body{
            background:radial-gradient(circle at top left,#000,#1a1a1a 80%);
            min-height:100vh;display:flex;flex-direction:column;
            justify-content:flex-start;align-items:center;
            color:#f5f5f5;padding-top:100px;
        }
        form{
            background:rgba(255,255,255,0.05);
            backdrop-filter:blur(12px);
            border:1px solid rgba(255,255,255,0.15);
            padding:40px 50px;border-radius:20px;
            box-shadow:0 0 30px rgba(255,255,255,0.05);
            width:420px;text-align:center;
        }
        h2{color:#fff;font-size:24px;font-weight:600;margin-bottom:25px;}
        table{width:100%;border-spacing:0 14px;}
        th{text-align:left;color:#ddd;font-weight:600;width:40%;padding-right:10px;}
        td{width:60%;}
        input,textarea{
            width:100%;padding:10px 12px;border:1px solid rgba(255,255,255,0.2);
            border-radius:6px;background:rgba(255,255,255,0.05);
            color:#fff;font-size:14px;
        }
        input:focus,textarea:focus{
            border-color:#00ffcc;box-shadow:0 0 6px rgba(0,255,204,0.5);
            outline:none;
        }
        input[type="submit"]{
            background:linear-gradient(135deg,#0ba29d,#5ca0d3);
            color:#fff;border:none;padding:10px 18px;
            border-radius:8px;cursor:pointer;font-weight:600;
            transition:0.3s;box-shadow:0 0 8px rgba(11,162,157,0.3);
        }
        input[type="submit"]:hover{
            transform:scale(1.05);
            background:linear-gradient(135deg,#5ca0d3,#0ba29d);
        }
        tr:last-child td{text-align:center;padding-top:10px;}
    </style>
</head>
<body>

<?php include("header.php"); ?>

<form action="" method="POST" onsubmit="return checkPasswords()">
    <h2>Student Registration</h2>
    <table>
        <tr><th>Enter Name</th><td><input name="name" type="text" required></td></tr>
        <tr><th>Enter Roll No</th><td><input name="roll" type="text" required></td></tr>
        <tr><th>Enter Address</th><td><textarea name="address" rows="3" required></textarea></td></tr>
        <tr><th>Enter Phone No</th><td><input name="phno" type="number" required></td></tr>
        <tr><th>Username</th><td><input name="username" type="text" autocomplete="new-username" required></td></tr>
        <tr><th>Password</th><td><input id="password" name="password" type="password" autocomplete="new-password" required></td></tr>
        <tr><th>Re-Type Password</th><td><input id="password1" name="password1" type="password" autocomplete="new-password" required></td></tr>
        <tr><td colspan="2"><input type="submit" name="submit" value="Register"></td></tr>
    </table>
</form>

<script>
function checkPasswords(){
    const pw=document.getElementById('password').value.trim();
    const pw1=document.getElementById('password1').value.trim();
    if(pw!==pw1){
        alert('⚠️ Passwords do not match. Please retype.');
        return false;
    }
    return true;
}
</script>
</body>
</html>
