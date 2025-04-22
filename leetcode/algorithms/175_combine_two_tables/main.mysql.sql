-- # Write your MySQL query statement below
SELECT person.firstName, person.lastName, address.city, address.state
FROM Person person LEFT OUTER JOIN Address address ON person.personId = address.personId;


-- Solution
-- Solution 1: table1 LEFT JOIN table2 ON condition
SELECT P.firstName, P.lastName, A.city, A.state
FROM Person P LEFT JOIN Address A
on P.personId = A.personId

-- Solution 2: table1 LEFT JOIN table2 USING column_name
SELECT P.firstName, P.lastName, A.city, A.state
FROM Person P
LEFT JOIN Address A USING (personId)
