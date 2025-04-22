-- /*
--  Please write a DELETE statement and DO NOT write a SELECT statement.
--  Write your PL/SQL query statement below
--  */
DELETE p1 
FROM person p1, person p2 
WHERE p1.email = p2.email 
AND p1.id > p2.id;


-- Solution
DELETE p1 FROM person p1, person p2 
WHERE p1.email = p2.email AND p1.id > p2.id;
