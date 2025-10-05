
-- @block
SELECT students.first_name, 
       students.last_name, 
       courses.course_name
FROM students
LEFT JOIN courses 
ON students.course_name = courses.course_name

UNION

SELECT students.first_name, 
       students.last_name, 
       courses.course_name
FROM students
RIGHT JOIN courses 
ON students.course_name = courses.course_name;
