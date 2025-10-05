-- @block
CREATE TABLE authors (
    id INT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE
);

-- @block
CREATE TABLE books (
    id INT PRIMARY KEY,
    title VARCHAR(100) NOT NULL,
    price DECIMAL(6, 2) CHECK (price > 0),
    author_id INT,
    FOREIGN KEY (author_id) REFERENCES authors(id)
);

-- @block
INSERT INTO authors (id, name, email) 
VALUES
    (1, 'Milan Bairagi', 'milan@email.com'),
    (2, 'laxmi Prasad Devkota', 'devkota@email.com'),
    (3, 'J. K. Rowling', 'j.k.rowling@email.com'),
    (4, 'Sanu Sharma', 'sanu.sharma.@yahoo.com')
;

-- @block
INSERT INTO books
VALUES 
    (1, "The Nonsense", 999.99, 1),
    (2, "Muna Madan", 500.99, 2),
    (3, "Shakuntala", 400.50, 2),
    (4, "Harry Potter", 700, 3),
    (5, "Te Saat Din", 600, 4)
;
-- @block
SELECT
    b.title AS Title, 
    a.name AS Author, 
    b.price AS Price
FROM authors a
JOIN books b
ON (a.id = b.author_id);

-- @block