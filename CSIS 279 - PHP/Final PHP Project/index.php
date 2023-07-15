<?php
require_once('database.php');

// Get category ids for selected category
$queryCategory = 'SELECT * FROM course as c JOIN Instructor as i on c.instructorID = i.instructorID';
$statement = $db->prepare($queryCategory);
$statement->execute();
$course = $statement->fetchAll();
$statement->closeCursor();

?>
<!DOCTYPE html>
<html>

<!-- the head section -->
<head>
    <title>Student Registration</title>
    <!-- Added meta line because I was having trouble with getting the CSS to update -->
    <meta http-equiv="Cache-Control" content="no-cache, no-store, must-revalidate" />
    <link rel="stylesheet" type="text/css" href="main.css" />
</head>

<!-- the body section -->
<body>
<header><h1>Student Registration Form</h1></header>
<main>
    <section>
        <form action='add_course.php' method='post'>
            <br>
            <h2>Student Information</h2>
            <p>(* is required)</p>
            <table>
                <tr>                
                    <td class='right'>*First Name:</td>
                    <td><input type='text' name='first_name'></td>
                </tr>
                <tr>                
                    <td class='right'>Middle Name:</td>
                    <td><input type='text' name='middle_name'></td>
                </tr>
                <tr>                
                    <td class='right'>*Last Name:</td>
                    <td><input type='text' name='last_name'></td>
                </tr>
            </table>
                       
            <!-- display courses to choose by check box -->
            <br>
            <h2>Select Courses</h2>
            <p>At least three are required, and no more than six.</p>
            <table>
                <tr>
                    <th>Course ID</th>
                    <th>Course Name</th>
                    <th>Instructor</th>
                    <th>Select</th>
                </tr>

                <?php foreach ($course as $courses) : ?>
                <tr>
                    <td><?php echo $courses['courseID']; ?></td>
                    <td><?php echo $courses['courseName']; ?></td>
                    <td><?php echo $courses['lastName']; ?></td>
                    <td><input type='checkbox' name='course_select[]' value='<?php echo $courses['courseID'] ?>'></td>
                </tr>
                <?php endforeach; ?>
            </table> 
            
            <br>
            <input type='hidden' value='<?php echo date("m/d/y h:i:sa") ?>' name='date' >
            <input type='submit' value='Submit Information' >
            
        </form>
        <br>
        <form action='instructors.php'>
            <input type='submit' value='About Instructors...' />
        </form>
    </section>
</main>
<footer>
    <p>&copy; <?php echo date("Y"); ?> McDaniel Services</p>
</footer>
</body>
</html>