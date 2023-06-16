-- # Please write a DELETE statement and DO NOT write a SELECT statement.
-- # Write your MySQL query statement below
DELETE p1 
FROM person p1 INNER JOIN person p2 
ON p1.email = p2.email 
WHERE p1.id > p2.id;


-- Best Solution
-- Using Cartesian Product
DELETE p1 FROM person p1, person p2 
WHERE p1.email = p2.email AND p1.id > p2.id;