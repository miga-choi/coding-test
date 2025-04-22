-- # Write your MySQL query statement below
SELECT name AS Employee
FROM Employee a
WHERE a.salary > (SELECT salary FROM Employee WHERE id = a.managerId);


-- Solution
SELECT e2.name AS Employee
FROM employee e1
INNER JOIN employee e2 ON e1.id = e2.managerId
WHERE e1.salary < e2.salary
