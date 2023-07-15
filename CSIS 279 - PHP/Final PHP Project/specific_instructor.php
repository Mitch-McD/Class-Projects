<?php
require_once('database.php');

// instructor ID
$instructorID = filter_input(INPUT_POST, 'select_instructor');

// Get instructor information
$queryInstructor = 'SELECT * FROM instructor '
        . 'WHERE instructorID = :instructorID';
$statement = $db->prepare($queryInstructor);
$statement->bindValue(':instructorID', $instructorID);
$statement->execute();
$instructor = $statement->fetch();
$statement->closeCursor();

// get instructor degrees, joining degree table with degreeinstructor linking table
$queryDegrees = 'SELECT * FROM degreeinstructor as di '
        . 'JOIN degree as d ON d.degreeID = di.degreeID '
        . 'WHERE di.instructorID = :instructorID';
$statement1 = $db->prepare($queryDegrees);
$statement1->bindValue(':instructorID', $instructorID);
$statement1->execute();
$instructor_degrees = $statement1->fetchAll();
$statement1->closeCursor();

?>
<!DOCTYPE html>
<html>

<head>
    <title>Student Registration</title>
    <meta http-equiv="Cache-Control" content="no-cache, no-store, must-revalidate" />
    <link rel="stylesheet" type="text/css" href="main.css" />
</head>
<body>
<header><h1>Student Registration Form</h1></header>
<main>
    <section>
            <br>
            <!-- Display single instructor information -->
            <h2>Instructor Information</h2>
            <label>ID: <?php echo $instructor['instructorID']; ?></label><br><br>
            <label>Name: <?php echo $instructor['firstName'] . " " . $instructor['lastName']; ?></label><br><br>
            <label>Office Hours: <?php echo $instructor['officeHours']; ?></label><br><br>
            <label>Room Number: <?php echo $instructor['roomNum']; ?></label><br><br>
            <label>Degrees: <?php
                foreach($instructor_degrees as $i_d) {
                    echo $i_d['degreeLevel'] . ' in ' . $i_d['degreeName'] . ", ";
                }
                ?></label><br><br>
                <label>Field of Expertise: <?php echo $instructor['field']; ?></label><br><br>
        <form action='instructors.php'>
            <input type='submit' value='Back' />
        </form>
    </section>
</main>
<footer>
    <p>&copy; <?php echo date("Y"); ?> McDaniel Services</p>
</footer>
</body>
</html>