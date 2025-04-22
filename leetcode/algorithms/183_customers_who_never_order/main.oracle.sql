-- /* Write your PL/SQL query statement below */
SELECT customers.name AS Customers 
FROM Customers customers, Orders orders 
WHERE customers.id = orders.customerId(+) AND orders.customerId IS NULL;


-- Solution
SELECT name AS Customers FROM Customers
WHERE Customers.id NOT IN (SELECT customerId FROM Orders);
