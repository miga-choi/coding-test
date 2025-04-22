-- # Write your MySQL query statement below
SELECT email AS Email 
FROM Person
GROUP BY email 
HAVING count(email) > 1;


-- Solution
-- Solution 1
SELECT email FROM Person
GROUP BY email
HAVING count(email) > 1;

-- Solution 2
SELECT DISTINCT(p1.email) FROM Person p1, Person p2
WHERE p1.id <> p2.id AND p1.email = p2.email;

-- Solution 3
SELECT DISTINCT(p1.email) FROM 
Person p1 JOIN Person p2 ON
p1.email = p2.email AND p1.id <> p2.id;
