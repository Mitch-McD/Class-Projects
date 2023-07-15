<?php
// Get the product data
$first_name = filter_input(INPUT_POST, 'first_name');
$middle_name = filter_input(INPUT_POST, 'middle_name');
$last_name = filter_input(INPUT_POST, 'last_name');
$course_select = filter_input(INPUT_POST, 'course_select', FILTER_SANITIZE_SPECIAL_CHARS, FILTER_REQUIRE_ARRAY);
$date = filter_input(INPUT_POST, 'date');

// check for if at least three classes have been taken
if ($course_select == null || $course_select == false || count($course_select) > 6 || count($course_select) < 3) {
    $error = "Invalid course select, please ensure you have at least 3 courses selected and no more than 6.";
    include('error.php');
    
// Validate inputs, middle name can be null
} else if ($date == null || $first_name == null || $last_name == null) {
    $error = "Invalid student information. Check all fields and try again.";
    include('error.php');

// write to database
} else {
    require_once('database.php');

    // Add the student's information to the student table
    $student_query = 'INSERT INTO student
                 (firstName, middleName, lastName, date)
              VALUES
                 (:first_name, :middle_name, :last_name, :date)';
    $statement0 = $db->prepare($student_query);
    $statement0->bindValue(':first_name', $first_name);
    $statement0->bindValue(':middle_name', $middle_name);
    $statement0->bindValue(':last_name', $last_name);
    $statement0->bindValue(':date', $date);
    $statement0->execute();
    $statement0->closeCursor();
    
    /* Gets student id after it's been created to use in third query
     * I couldn't think of a better way to do this but I'm sure there is one
     * Uses name and date to uniquely select the student id to pair, could pose
     * problems if a same name was entered at the exact same second
     */
    $get_studentid_query = 'select studentID from Student
                 where firstName = :first_name
                 and middleName = :middle_name
                 and lastName = :last_name
                 and date = :date';
    $statement1 = $db->prepare($get_studentid_query);
    $statement1->bindValue(':first_name', $first_name);
    $statement1->bindValue(':middle_name', $middle_name);
    $statement1->bindValue(':last_name', $last_name);
    $statement1->bindValue(':date', $date);
    $statement1->execute();
    $student_id = $statement1->fetch();
    $statement1->closeCursor();
    
    // Links student id for each course id that was selected
    foreach($course_select as $course_id) :
        $relational_query = 'INSERT INTO studentcourse
                     (courseID, studentID)
                  VALUES
                     (:course_id, :student_id)';
        $statement2 = $db->prepare($relational_query);
        $statement2->bindValue(':course_id', $course_id);
        $statement2->bindValue(':student_id', $student_id['studentID']);
        $statement2->execute();
        $statement2->closeCursor();
    endforeach;
    
    // clear fields and referesh index page because for whatever reason 
    // refreshing this page re-executes the queries
    header("Location: ./index.php"); 
}
?>