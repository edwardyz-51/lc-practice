-- Write your query below
SELECT c.customer_id
FROM customers c
WHERE c.year = 2020
AND c.revenue > 0
