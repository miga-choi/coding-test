SELECT S.name AS name
FROM Orders O 
INNER JOIN Company C ON O.com_id = C.com_id AND C.name = 'RED'
RIGHT JOIN SalesPerson S ON S.sales_id = O.sales_id
WHERE O.order_id IS NULL;

-- Solution
SELECT SalesPerson.name
FROM Orders O JOIN Company C ON (O.com_id = C.com_id AND C.name = 'RED')
RIGHT JOIN SalesPerson ON SalesPerson.sales_id = O.sales_id
WHERE O.sales_id IS NULL;
