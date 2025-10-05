
-- @block
CREATE TABLE Students (
    id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    email VARCHAR(100) NULL,
    mobile_number VARCHAR(15) NULL
);

-- @block
INSERT INTO Students (first_name, last_name, email, mobile_number)
VALUES
    ('Milan', 'Bairagi', 'milan@gmail.com', NULL),
    ('Peter', 'Parker', NULL, '9876543210');

-- @block
SELECT * FROM Students;

-- @block
SELECT * FROM Students 
WHERE email IS NULL;

-- @block
SELECT * FROM Students 
WHERE mobile_number IS NOT NULL;
