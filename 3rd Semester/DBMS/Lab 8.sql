
-- @block
SELECT category, COUNT(*) AS total_products
FROM products
GROUP BY category;
