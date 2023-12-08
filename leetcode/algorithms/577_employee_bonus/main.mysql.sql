-- # Write your MySQL query statement below
SELECT employee.name AS name,
    bonus.bonus AS bonus
FROM Employee employee
    LEFT OUTER JOIN Bonus bonus ON employee.empId = bonus.empId
WHERE IFNULL(bonus.bonus, 0) < 1000;


-- # Best Solution 1
SELECT Employee.name,
    Bonus.bonus
FROM Employee
    LEFT JOIN Bonus ON Employee.empID = Bonus.empID
WHERE bonus < 1000
    OR Bonus IS NULL;

-- # Best Solution 2
SELECT name,
    bonus
FROM Employee
    LEFT JOIN Bonus USING(empId)
WHERE COALESCE(bonus, 0) < 1000;