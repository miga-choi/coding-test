-- # Write your MySQL query statement below
SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(student) >= 5;


-- # Best Solution
-- # Best Solution 1: Having
SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(student) >= 5;

-- # Best Solution 2: Subquery
SELECT class
FROM (
        SELECT class,
            COUNT(student) AS num
        FROM courses
        GROUP BY class
    ) AS temp
WHERE num >= 5;