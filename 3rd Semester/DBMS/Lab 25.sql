
-- @block
ALTER TABLE students
ADD COLUMN course_name VARCHAR(100);

-- @block
UPDATE students SET course_name = 'BIT' WHERE id = 1;
UPDATE students SET course_name = 'BSc. CSIT' WHERE id = 2;
UPDATE students SET course_name = 'BBS' WHERE id = 3;
UPDATE students SET course_name = 'BIT' WHERE id = 4;
UPDATE students SET course_name = 'BIT' WHERE id = 5;
UPDATE students SET course_name = 'BBA' WHERE id = 6;

-- @block
SELECT * FROM students;

-- @block
SELECT s.first_name, 
        s.last_name,
        c.course_name
FROM students s
JOIN courses c
USING (course_name);
