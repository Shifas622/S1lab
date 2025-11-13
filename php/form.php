<html>
<head>
    <title>Student Marks Form</title>

    <style>
        /* 🌑 Universal Reset */
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: "Poppins", sans-serif;
        }

        /* 🌌 Background */
        body {
            background: radial-gradient(circle at top left, #000000, #1a1a1a 80%);
            height: 100vh;
            display: flex;
            justify-content: center;
            align-items: center;
            color: #f5f5f5;
        }

        /* 🪟 Glass Form Container */
        form {
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

        /* 🧾 Heading */
        h2 {
            color: #fff;
            font-size: 24px;
            font-weight: 600;
            letter-spacing: 1px;
            margin-bottom: 25px;
            text-shadow: 0 0 6px rgba(255, 255, 255, 0.25);
        }

        /* 📋 Table Layout */
        table {
            width: 100%;
            border-spacing: 0 12px;
        }

        th {
            text-align: left;
            color: #ddd;
            font-weight: 600;
            width: 40%;
            font-size: 15px;
            padding-right: 10px;
            text-shadow: 0 0 4px rgba(255, 255, 255, 0.2);
        }

        td {
            width: 60%;
        }

        /* ✏️ Input Fields */
        input[type="text"] {
            width: 100%;
            padding: 10px 12px;
            border: 1px solid rgba(255, 255, 255, 0.2);
            border-radius: 6px;
            font-size: 14px;
            background: rgba(255, 255, 255, 0.05);
            color: #fff;
            transition: all 0.3s;
        }

        input[type="text"]:focus {
            outline: none;
            border-color: #00ffcc;
            box-shadow: 0 0 6px rgba(0, 255, 204, 0.5);
            background: rgba(255, 255, 255, 0.08);
        }

        /* 🔘 Buttons */
        input[type="submit"], button {
            background: linear-gradient(135deg, #0ba29d, #5ca0d3);
            color: #fff;
            border: none;
            padding: 10px 18px;
            border-radius: 8px;
            cursor: pointer;
            font-weight: 600;
            transition: all 0.3s ease;
            box-shadow: 0 0 8px rgba(11, 162, 157, 0.3);
        }

        input[type="submit"]:hover,
        button:hover {
            background: linear-gradient(135deg, #5ca0d3, #0ba29d);
            transform: scale(1.05);
            box-shadow: 0 0 12px rgba(11, 162, 157, 0.5);
        }

        /* ⚙️ Calculate Section */
        #button {
            text-align: center;
        }

        #button span {
            display: block;
            margin-top: 8px;
            color: #00ffcc;
            font-weight: 600;
            text-shadow: 0 0 6px rgba(0, 255, 204, 0.3);
        }

        /* 🎯 Buttons Alignment */
        tr:last-child td {
            text-align: center;
        }

        /* 📱 Responsive */
        @media (max-width: 480px) {
            form {
                width: 90%;
                padding: 30px 25px;
            }

            h2 {
                font-size: 20px;
            }

            th, td {
                display: block;
                width: 100%;
                text-align: left;
                margin-bottom: 8px;
            }

            tr:last-child td {
                display: inline-block;
                width: 48%;
                text-align: center;
            }
        }
    </style>

    <script>
        function calculate() {
            let m1 = parseInt(document.getElementsByName("Mark1")[0].value) || 0;
            let m2 = parseInt(document.getElementsByName("Mark2")[0].value) || 0;
            let m3 = parseInt(document.getElementsByName("Mark3")[0].value) || 0;

            let total = m1 + m2 + m3;

            document.getElementById("button").innerHTML = `
                <button type='button' onclick='calculate()'>Calculate</button>
                <span>Total Marks: ${total}</span>
            `;
        }
    </script>
</head>

<body>
<?php  
echo "
    <form action='validate.php' method='POST'>
        <h2>Student Marks Form</h2>
        <table>
            <tr>
                <th>Enter Name</th>
                <td><input name='name' type='text' required></td>
            </tr>

            <tr>
                <th>Enter Roll No</th>
                <td><input name='roll' type='text' required></td>
            </tr>

            <tr>
                <th>Enter Mark 1</th>
                <td><input name='Mark1' type='text' required></td>
            </tr>

            <tr>
                <th>Enter Mark 2</th>
                <td><input name='Mark2' type='text' required></td>
            </tr>

            <tr>
                <th>Enter Mark 3</th>
                <td><input name='Mark3' type='text' required></td>
            </tr>

            <tr>
                <td><input type='submit' value='Submit'></td>
                <td id='button'><button type='button' onclick='calculate()'>Calculate</button></td>
            </tr>
        </table>
    </form>";
?>
</body>
</html>
