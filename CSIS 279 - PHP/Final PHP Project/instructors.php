<?php
require_once('database.php');

// Get list of instructors
$queryCategory = 'SELECT * FROM instructor';
$statement = $db->prepare($queryCategory);
$statement->execute();
$instructors = $statement->fetchAll();
$statement->closeCursor();

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
            <h2>List of Current Instructors:</h2>
            <table>
                <tr>
                    <th>Instructor ID</th>
                    <th>Instructor Name</th>
                    <th>More Info</th>
                </tr>
                <!-- display instructors -->
                <form action='specific_instructor.php' method='post'>
                    <?php foreach ($instructors as $i) : ?>
                    
                    <tr>
                        <td><?php echo $i['instructorID']; ?></td>
                        <td><?php echo $i['firstName'] . ' ' . $i['lastName']; ?></td>
                        <td>
                            <button type='submit' name='select_instructor' value='<?php echo $i['instructorID'] ?>' >More Info</button>
                        </td>
                    </tr>
                    <?php endforeach; ?>
                </form>
            </table> 
            <br>            
            <!-- Back to home page -->
        <form action='index.php'>
            <input type='submit' value='Back' />
        </form>
    </section>
</main>
<footer>
    <p>&copy; <?php echo date("Y"); ?> McDaniel Services</p>
</footer>
</body>
</html>