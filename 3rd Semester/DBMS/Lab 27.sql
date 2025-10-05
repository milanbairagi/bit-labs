
-- @block
SELECT s.first_name, 
        s.last_name, 
        c.course_name
FROM students s
LEFT OUTER JOIN courses c
ON (s.course_name = c.course_name);