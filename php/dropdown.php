<?php
include "connection.php";


$roll_query = "SELECT rollno FROM stud";
$result = mysqli_query($con, $roll_query);
if (isset($_POST['update'])) {
    $rollno = $_POST['rollno'];
    $mark1 = $_POST['mark1'];
    $mark2 = $_POST['mark2'];
    $total = $mark1 + $mark2;

    $update = "UPDATE stud SET mark1='$mark1', mark2='$mark2', total='$total' WHERE rollno='$rollno'";

    if (mysqli_query($con, $update)) {
        echo "<p style='color:lime;'>✅ Student record updated successfully!</p>";
    } else {
        echo "<p style='color:red;'>❌ Error updating record: " . mysqli_error($con) . "</p>";
    }
}

if (isset($_POST['show'])) {
    $rollno = $_POST['drop'];

    $sql = "SELECT * FROM stud WHERE rollno = '$rollno'";
    $result1 = mysqli_query($con, $sql);

    if ($row = mysqli_fetch_assoc($result1)) {
        ?>
        <h3>Student Details</h3>

        <form method="POST">
            <input type="hidden" name="rollno" value="<?php echo $row['rollno']; ?>">
            Roll No: <?php echo $row['rollno']; ?><br>
            Name: <?php echo htmlspecialchars($row['name']); ?><br><br>

            Mark1: <input type="number" name="mark1" value="<?php echo $row['mark1']; ?>"><br>
            Mark2: <input type="number" name="mark2" value="<?php echo $row['mark2']; ?>"><br>
            Total: <?php echo $row['total']; ?><br><br>

            <input type="submit" name="update" value="Update">
        </form>
        <?php
    } else {
        echo "<p style='color:red;'>No record found for Roll No $rollno</p>";
    }
}
?>

<!-- ✅ Step 3: Roll Number Dropdown -->
<form action="" method="POST">
    <select name="drop" required>
        <option value="">Select roll no</option>
        <?php
        mysqli_data_seek($result, 0); // reset pointer for re-use
        while ($row = mysqli_fetch_assoc($result)) {
            echo "<option value='" . $row['rollno'] . "'>" . $row['rollno'] . "</option>";
        }
        ?>
    </select>
    <input type="submit" name="show" value="Show Details">
</form>
