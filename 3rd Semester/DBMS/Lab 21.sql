SELECT * from students;

-- @block
SELECT id, first_name, last_name
FROM students
WHERE NOT first_name = 'Peter';