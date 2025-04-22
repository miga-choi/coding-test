-- # Write your MySQL query statement below
SELECT customers.name AS Customers 
FROM Customers customers LEFT OUTER JOIN Orders orders 
ON customers.id = orders.customerId 
WHERE orders.customerId IS NULL;


-- Solution
SELECT name AS Customers
FROM Customers
WHERE id NOT IN (
    SELECT customerId
    FROM Orders
);
