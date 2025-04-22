-- /* Write your PL/SQL query statement below */
SELECT a.name AS Employee 
FROM Employee a INNER JOIN Employee b ON a.managerId = b.id 
WHERE a.salary > b.salary;


-- Solution
SELECT e1.name AS 'Employee'
FROM Employee e1
LEFT JOIN Employee e2
ON e1.managerId = e2.id
WHERE e1.salary > e2.salary
