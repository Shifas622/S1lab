<html>
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
            background: radial-gradient(circle at top left, #000000, #1a1a1a 80%);
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            color: #f5f5f5;
        }

        /* 🪟 Glass Card Container */
        .container {
            background: rgba(255, 255, 255, 0.05);
            backdrop-filter: blur(12px);
            -webkit-backdrop-filter: blur(12px);
            border: 1px solid rgba(255, 255, 255, 0.15);
            padding: 40px 50px;
            border-radius: 20px;
            box-shadow: 0 0 30px rgba(255, 255, 255, 0.05);
            width: 420px;
            text-align: center;
            animation: fadeIn 0.6s ease;
        }

        @keyframes fadeIn {
            from { opacity: 0; transform: translateY(20px); }
            to { opacity: 1; transform: translateY(0); }
        }

        /* ✨ Title */
        h3 {
            color: #ffffff;
            font-size: 24px;
            font-weight: 600;
            letter-spacing: 1px;
            margin-bottom: 25px;
            text-shadow: 0 0 5px rgba(255, 255, 255, 0.3);
        }

        /* 🧾 Table Styles */
        table {
            width: 100%;
            border-collapse: separate;
            border-spacing: 0 12px;
        }

        th {
            text-align: left;
            background: rgba(255, 255, 255, 0.08);
            color: #f0f0f0;
            padding: 10px 14px;
            border-radius: 8px 0 0 8px;
            font-weight: 600;
            font-size: 14px;
            text-shadow: 0 0 4px rgba(255, 255, 255, 0.2);
        }

        td {
            text-align: left;
            background: rgba(255, 255, 255, 0.03);
            color: #e0e0e0;
            padding: 10px 14px;
            border-radius: 0 8px 8px 0;
            font-size: 14px;
            font-weight: 400;
        }

        /* 🌈 Total / Highlight Rows */
        tr:last-child td {
            font-weight: 600;
            color: #fff;
            background: rgba(255, 255, 255, 0.1);
        }

        /* 🟢 Grade Color Variants */
        .grade-Aplus { color: #00ff9d; font-weight: bold; }
        .grade-A { color: #32e875; font-weight: bold; }
        .grade-B { color: #9eff32; font-weight: bold; }
        .grade-C { color: #ffda66; font-weight: bold; }
        .grade-D { color: #ff9966; font-weight: bold; }
        .grade-F { color: #ff4d4d; font-weight: bold; }

        /* 🔙 Back Button */
        .back-btn {
            margin-top: 25px;
            display: inline-block;
            background: rgba(255, 255, 255, 0.1);
            color: #fff;
            padding: 10px 22px;
            border-radius: 8px;
            text-decoration: none;
            font-weight: 600;
            letter-spacing: 0.5px;
            border: 1px solid rgba(255, 255, 255, 0.15);
            transition: all 0.3s ease;
        }

        .back-btn:hover {
            background: rgba(255, 255, 255, 0.2);
            transform: scale(1.05);
        }

        /* 📱 Responsive */
        @media (max-width: 480px) {
            .container {
                width: 90%;
                padding: 25px 30px;
            }

            h3 {
                font-size: 20px;
            }

            th, td {
                font-size: 13px;
                padding: 8px 10px;
            }
        }
    </style>
</head>

<body>
<?php
// ✅ Capture form data safely
$name = $_POST['name'] ?? '';
$roll = $_POST['roll'] ?? '';
$Mark1 = (int)($_POST['Mark1'] ?? 0);
$Mark2 = (int)($_POST['Mark2'] ?? 0);
$Mark3 = (int)($_POST['Mark3'] ?? 0);

$tmark = $Mark1 + $Mark2 + $Mark3;
$percentage = $tmark / 3;
$grade = '';
$gradeClass = '';

if ($percentage >= 90) { $grade = 'A+'; $gradeClass = 'grade-Aplus'; }
elseif ($percentage >= 80) { $grade = 'A'; $gradeClass = 'grade-A'; }
elseif ($percentage >= 70) { $grade = 'B'; $gradeClass = 'grade-B'; }
elseif ($percentage >= 60) { $grade = 'C'; $gradeClass = 'grade-C'; }
elseif ($percentage >= 50) { $grade = 'D'; $gradeClass = 'grade-D'; }
else { $grade = 'F'; $gradeClass = 'grade-F'; }
?>

<div class="container">
    <h3>Student Details</h3>
    <table>
        <tr>
            <th>Name</th>
            <td><?php echo htmlspecialchars($name); ?></td>
        </tr>
        <tr>
            <th>Roll No</th>
            <td><?php echo htmlspecialchars($roll); ?></td>
        </tr>
        <tr>
            <th>Mark 1</th>
            <td><?php echo $Mark1; ?></td>
        </tr>
        <tr>
            <th>Mark 2</th>
            <td><?php echo $Mark2; ?></td>
        </tr>
        <tr>
            <th>Mark 3</th>
            <td><?php echo $Mark3; ?></td>
        </tr>
        <tr>
            <th>Total Marks</th>
            <td><?php echo $tmark; ?></td>
        </tr>
        <tr>
            <th>Percentage</th>
            <td><?php echo number_format($percentage, 2) . '%'; ?></td>
        </tr>
        <tr>
            <th>Grade</th>
            <td class="<?php echo $gradeClass; ?>"><?php echo $grade; ?></td>
        </tr>
    </table>

    <a href="form.php" class="back-btn">⬅ Back to Form</a>
</div>
</body>
</html>
