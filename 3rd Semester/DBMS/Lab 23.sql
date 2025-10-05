CREATE TABLE Courses (
    id INT PRIMARY KEY,
    course_name VARCHAR(100)
);

-- @block
INSERT INTO courses (id, course_name)
VALUES
    (1, 'BIT'),
    (2, 'BSc. CSIT'),
    (3, 'BSc'),
    (4, 'BBA'),
    (5, 'BHM'),
    (6, 'BBs')
;

-- @block
SELECT * FROM courses;

-- @block
SELECT 
    CONCAT(students.first_name, ' ', students.last_name) AS Name, 
    courses.course_name AS Course
FROM students
CROSS JOIN courses
LIMIT 10;
