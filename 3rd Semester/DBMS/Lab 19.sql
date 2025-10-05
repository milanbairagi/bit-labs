
-- @block
SELECT id, name, price
FROM products
WHERE name LIKE 'L%'
AND price < 100;
