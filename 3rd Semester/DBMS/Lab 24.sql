
-- @block
SELECT 
    students.first_name AS Name, 
    courses.course_name AS Course
FROM students
NATURAL JOIN courses;
