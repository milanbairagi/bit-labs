INSERT INTO students (first_name, last_name)
VALUES
    ('Sasuke', 'Uchiha'),
    ('Shikamaru', 'Nara'),
    ('Neji', 'Hyuga'),
    ('Kakashi', 'Hatake')
;

-- @block
SELECT * FROM students;

-- @block
CREATE TABLE captains (
    id INT PRIMARY KEY,
    student_id INT NOT NULL,
    FOREIGN KEY (student_id) REFERENCES students(id)
);

-- @block
INSERT INTO captains (id, student_id)
VALUES (1, 1), (2, 4), (3, 5);

-- @block
SELECT * FROM captains;

-- @block
SELECT * FROM students
WHERE id IN (
    SELECT student_id FROM captains
);
