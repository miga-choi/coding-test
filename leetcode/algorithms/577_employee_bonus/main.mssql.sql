-- /* Write your T-SQL query statement below */
SELECT Employee.name, Bonus.bonus
FROM Employee
    LEFT OUTER JOIN Bonus ON Employee.empId = Bonus.empId
WHERE ISNULL(Bonus.bonus, 0) < 1000;


-- /* Solution */
-- /* Solution 1: Basic */
SELECT e.name, b.bonus
FROM Employee e
    LEFT JOIN Bonus b USING(empId)
WHERE bonus < 1000
    OR bonus IS NULL;

-- /* Solution 2: ISNULL */
SELECT e.name, b.bonus
FROM Employee e
    LEFT JOIN bonus b USING(empId)
WHERE ISNULL(b.bonus, 0) < 1000;
