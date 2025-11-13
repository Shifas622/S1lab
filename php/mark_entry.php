<?php
include("connection.php"); // Make sure this connects to your DB correctly
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Mark Entry</title>

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
            width:420px;text-align:left;
        }
        h2{color:#fff;font-size:24px;font-weight:600;margin-bottom:25px;text-align:center;}
        table{width:100%;border-spacing:0 12px;}
        th{text-align:left;color:#ddd;font-weight:600;width:40%;padding-right:10px;vertical-align:middle;}
        td{width:60%;vertical-align:middle;}
        input, select, textarea{
            width:100%;padding:10px 12px;border:1px solid rgba(255,255,255,0.2);
            border-radius:6px;background:rgba(255,255,255,0.05);
            color:#fff;font-size:14px;
        }
        input:focus, select:focus, textarea:focus{
            border-color:#00ffcc;box-shadow:0 0 6px rgba(0,255,204,0.5);outline:none;
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
        tr td[colspan="2"]{text-align:center;padding-top:15px;}
        select{-webkit-appearance:none;-moz-appearance:none;appearance:none;background:rgba(255,255,255,0.05);color:#fff;}
    </style>
</head>
<body>
    <h2>Enter Marks</h2>

    <form action="" method="GET">
        <table>
            <!-- Roll No Dropdown -->
            <tr>
                <th>Roll No</th>
                <td>
                    <select name="roll">
                        <option value="">--Select Roll No--</option>
                        <?php
                        $sql = "SELECT rollno FROM stud";
                        $result = mysqli_query($con, $sql);
                        if ($result && mysqli_num_rows($result) > 0) {
                            while ($row = mysqli_fetch_assoc($result)) {
                                $selected = (isset($_GET['roll']) && $_GET['roll'] == $row['rollno']) ? "selected" : "";
                                echo "<option value='" . $row['rollno'] . "' $selected>" . $row['rollno'] . "</option>";
                            }
                        }
                        ?>
                    </select>
                </td>
                <td><input type="submit" name="show_name" value="Show Name"></td>
            </tr>

            <?php
            // Show student name and marks fields if a roll number is selected
            if (isset($_GET["show_name"]) && !empty($_GET["roll"])) {
                $roll = $_GET["roll"];
                $sql2 = "SELECT name FROM stud WHERE rollno='$roll'";
                $result2 = mysqli_query($con, $sql2);
                if ($row2 = mysqli_fetch_assoc($result2)) {
                    echo '<tr>
                            <th>Name</th>
                            <td colspan="2">' . $row2['name'] . '</td>
                          </tr>';
                    echo '<tr>
                            <th>Science</th>
                            <td colspan="2"><input type="number" name="science" required></td>
                          </tr>';
                    echo '<tr>
                            <th>Maths</th>
                            <td colspan="2"><input type="number" name="maths" required></td>
                          </tr>';
                    echo '<tr>
                            <th>English</th>
                            <td colspan="2"><input type="number" name="english" required></td>
                          </tr>';
                    echo '<tr>
                            <td colspan="2"><input type="submit" name="submit_marks" value="Submit Marks"></td>
                          </tr>';
                }
            }

            // Handle marks submission
            if (isset($_GET["submit_marks"])) {
                $roll = $_GET["roll"];
                $science = $_GET["science"];
                $maths = $_GET["maths"];
                $english = $_GET["english"];

                // Example: Insert marks into a marks table (adjust table/columns as needed)
                $insert_sql = "INSERT INTO marks (rollno, science, maths, english) VALUES ('$roll', '$science', '$maths', '$english')";
                if (mysqli_query($con, $insert_sql)) {
                    echo '<tr><td colspan="2" style="color:#0f0;">Marks submitted successfully!</td></tr>';
                } else {
                    echo '<tr><td colspan="2" style="color:#f00;">Error: ' . mysqli_error($con) . '</td></tr>';
                }
            }
            ?>
        </table>
    </form>
</body>
</html>
