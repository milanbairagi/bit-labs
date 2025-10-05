
-- @block
SELECT 
    id,
    name,
    price + price * 0.1 as price_with_10_percent,
    (price + 10) * 0.9 as service_charge_then_discounted
FROM products;
