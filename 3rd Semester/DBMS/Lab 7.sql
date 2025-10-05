-- @block
INSERT INTO products (name, price, supplier, category)
VALUES
    ('Laptop', 999.99, 'Dell', 'Electronics'),
    ('Smartphone', 799.99, 'Samsung', 'Electronics'),
    ('Tablet', 499.99, 'Apple', 'Electronics'),
    ('T-shirt', 19.99, 'Nike', 'Fashion'),
    ('Jeans', 49.99, 'Levis', 'Fashion'),
    ('Jacket', 89.99, 'Adidas', 'Fashion')
;

-- @block
SELECT
    COUNT(*) AS total_products,
    MIN(price) AS min_price,
    MAX(price) AS max_price
FROM products;
