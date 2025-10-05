SELECT * FROM products;

-- @block
SELECT name, category, price
FROM products
WHERE category = 'Fashion'
OR category = 'Toys';