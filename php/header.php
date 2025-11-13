<!-- header.php -->
<style>
    /* 🌌 Header Navigation */
    .header-nav {
        width: 100%;
        display: flex;
        justify-content: center;
        align-items: center;
        background: rgba(255, 255, 255, 0.05);
        backdrop-filter: blur(10px);
        -webkit-backdrop-filter: blur(10px);
        border-bottom: 1px solid rgba(255, 255, 255, 0.15);
        padding: 15px 0;
        position: fixed; /* Keeps it at the top */
        top: 0;
        left: 0;
        z-index: 1000;
    }

    .header-nav a {
        color: #00ffcc;
        text-decoration: none;
        font-weight: 600;
        margin: 0 20px;
        font-size: 15px;
        transition: all 0.3s ease;
        text-shadow: 0 0 5px rgba(0, 255, 204, 0.3);
    }

    .header-nav a:hover {
        color: #fff;
        transform: scale(1.1);
        text-shadow: 0 0 10px rgba(0, 255, 204, 0.6);
    }

    /* 📱 Responsive Header */
    @media (max-width: 600px) {
        .header-nav {
            flex-wrap: wrap;
            text-align: center;
            padding: 10px;
        }

        .header-nav a {
            margin: 8px 10px;
            font-size: 14px;
            display: inline-block;
        }
    }
</style>

<div class="header-nav">
    <a href="admin_dash.php";>Admin Dashbord</a>
    <a href="student_registration.php">Student Registration</a>
    <a href="mark_entry.php">Marks Entry</a>
    <a href="mark_update.php">Marks Update</a>
    <a href="Delete_student.php">Delete/Update Student</a>
    <a href="View_progress.php">View Progress</a>
</div>
