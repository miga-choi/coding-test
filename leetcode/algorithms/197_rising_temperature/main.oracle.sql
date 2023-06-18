-- /* Write your PL/SQL query statement below */
SELECT w2.id 
FROM Weather w1, Weather w2 
WHERE DATEDIFF(w2.recordDate, w1.recordDate) = 1 
AND w2.temperature > w1.temperature;


-- Best Solution
-- best solution1
SELECT Today.id 
FROM Weather Today, Weather Yesterday 
WHERE DATEDIFF(Today.recordDate, Yesterday.recordDate) = 1 
AND Today.temperature > Yesterday.temperature;

-- best solution2
SELECT Today.id 
FROM Weather Today, Weather Yesterday 
WHERE DATEDIFF(DAY, Today.recordDate, Yesterday.recordDate) = -1 
AND Today.temperature > Yesterday.temperature;