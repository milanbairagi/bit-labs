
-- @block
SELECT id, name, price,
(price - 0.2 * price) AS Discounted_price
FROM products;