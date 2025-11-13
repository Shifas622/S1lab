<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin Dashboard </title>
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

<?php
include("header.php");
?>  

</body>
</html>