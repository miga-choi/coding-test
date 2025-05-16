-- /* Write your PL/SQL query statement below */
SELECT employee.name AS name, bonus.bonus AS bonus
FROM Employee employee, Bonus bonus
WHERE employee.empId = bonus.empId(+)
    AND NVL(bonus.bonus, 0) < 1000;


--  /* Solution */
SELECT E.name, B.bonus
FROM Employee E
    LEFT OUTER JOIN Bonus B ON E.empId = B.empId
WHERE B.bonus < 1000
    OR bonus IS NULL
