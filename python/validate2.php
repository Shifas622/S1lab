<?php
$con=mysqli_connect("localhost","root","","student");
if(!$con)
{
    die("it cannot connected");
}
$name = $_POST['name'] ?? '';
$roll = $_POST['roll'] ?? '';
$mark1 =$_POST['mark1'];
$mark2 =$_POST['mark2'];
$total=$mark1+$mark2;

if($con)
{
    $sql1="Select rollno from stud where rollno='$roll'";
    $result=mysqli_query($con,$sql1);
    if(mysqli_num_rows($result)>0)
    {
        die("<script>alert('Cannot Insert The Value!!!Already Exist'); window.location='form_2_roll_mark.php'</script>");
    }
    $sql = "INSERT INTO stud (name,rollno,mark1,mark2,total) VALUES ('$name', '$roll','$mark1','$mark2','$total')";
    echo"<script>alert('Inserted Succesfully');</script>";
    
}



 
if (mysqli_query($con,$sql))
{
    echo"<script>alert('succesfull')</script>";
}

?>
<head>
    <title>Student Details</title>

    <style>
       /* 🌑 Global Reset */
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
    font-family: "Poppins", sans-serif;
}

/* 🌌 Background */
body {
    background: radial-gradient(circle at top left, #0d0d0d, #1a1a1a 80%);
    display: flex;
    justify-content: center;
    align-items: center;
    min-height: 100vh;
    color: #f5f5f5;
    padding: 20px;
}

/* 🪟 Glass Card Container */
.container {
    background: rgba(255, 255, 255, 0.06);
    backdrop-filter: blur(15px);
    -webkit-backdrop-filter: blur(15px);
    border: 1px solid rgba(255, 255, 255, 0.2);
    padding: 40px 50px;
    border-radius: 20px;
    box-shadow: 0 10px 40px rgba(0, 0, 0, 0.5);
    width: 450px;
    max-width: 100%;
    text-align: center;
    animation: fadeIn 0.6s ease;
}

/* Fade-in Animation */
@keyframes fadeIn {
    from { opacity: 0; transform: translateY(20px); }
    to { opacity: 1; transform: translateY(0); }
}

/* ✨ Title */
h3 {
    color: #ffffff;
    font-size: 26px;
    font-weight: 600;
    letter-spacing: 1px;
    margin-bottom: 25px;
    text-shadow: 0 0 5px rgba(255, 255, 255, 0.4);
}

/* 🧾 Table Styles */
table {
    width: 100%;
    border-collapse: separate;
    border-spacing: 0 12px;
    margin-bottom: 20px;
}

th, td {
    padding: 12px 15px;
    font-size: 14px;
    text-align: left;
    border-radius: 8px;
}

/* Header */
th {
    background: rgba(255, 255, 255, 0.1);
    color: #f0f0f0;
    font-weight: 600;
    text-shadow: 0 0 4px rgba(255, 255, 255, 0.2);
}

/* Body cells */
td {
    background: rgba(255, 255, 255, 0.04);
    color: #e0e0e0;
    font-weight: 400;
}

/* Hover effect for rows */
tr:hover td {
    background: rgba(255, 255, 255, 0.08);
    transition: 0.3s;
}

/* Highlight Total Row */
tr:last-child td {
    font-weight: 600;
    color: #fff;
    background: rgba(255, 255, 255, 0.12);
}

/* 🟢 Grade Colors */
.grade-Aplus { color: #00ff9d; font-weight: bold; }
.grade-A { color: #32e875; font-weight: bold; }
.grade-B { color: #9eff32; font-weight: bold; }
.grade-C { color: #ffda66; font-weight: bold; }
.grade-D { color: #ff9966; font-weight: bold; }
.grade-F { color: #ff4d4d; font-weight: bold; }

/* 🔙 Back Button */
.back-btn {
    display: inline-block;
    background: rgba(255, 255, 255, 0.08);
    color: #fff;
    padding: 12px 25px;
    border-radius: 10px;
    text-decoration: none;
    font-weight: 600;
    letter-spacing: 0.5px;
    border: 1px solid rgba(255, 255, 255, 0.2);
    transition: all 0.3s ease;
}

.back-btn:hover {
    background: rgba(255, 255, 255, 0.15);
    transform: scale(1.05);
}

/* 📱 Responsive */
@media (max-width: 480px) {
    .container {
        width: 95%;
        padding: 25px 20px;
    }

    h3 {
        font-size: 20px;
    }

    th, td {
        font-size: 13px;
        padding: 10px 8px;
    }
}

    </style>
</head>

<body>


<div class="container">
    <h3>Student Details</h3>
    <table>
        <tr>
            <th>Name</th>
            <th>Roll No</th>
            <th>mark1</th>
            <th>mark2</th>
            <th>Total marks</th>
        </tr>
       <?php
       $sql2="Select * from stud";
       $result = mysqli_query($con, $sql2);
       if(mysqli_num_rows($result)>0)
            {
                while($row=mysqli_fetch_assoc($result))
                {
                    echo "<tr>";
                    echo"<td>".$row['name']."</td>";
                    echo"<td>".$row['rollno']."</td>";
                    echo"<td>".$row['mark1']."</td>";
                    echo"<td>".$row['mark2']."</td>";
                    echo"<td>".$row['total']."</td>";
                    echo"</tr>";
                }

            }
            ?>
    </table>

    <a href="form_2_roll_mark.php" class="back-btn">⬅ Back to Form</a>
</div>
</body>
</html>
