
-- @block
CREATE TABLE products (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(255),
    price DECIMAL(10, 2),
    supplier VARCHAR(255),
    category VARCHAR(255)
);


-- @block 
INSERT INTO products (name, price, supplier, category) 
VALUES 
    ("Samsung Tablet", 299.99, "Samsung Electronics", "Electronics"),
    ("Nike Air Max", 129.99, "Sports Hub", "Fashion"),
    ("Coffee Maker", 89.99, "Kitchen Plus", "Appliances"),
    ("Harry Potter Book", 19.99, "Book World", "Books"),
    ("Lego Set", 59.99, "Toy Store", "Toys"),
    ("Leather Wallet", 45.99, "Fashion Hub", "Accessories")
;