
-- @block
SELECT supplier, AVG(price) as AvgPrice
FROM products
GROUP BY supplier
HAVING AVG(price) > 100;
