-- # Write your MySQL query statement below
SELECT w2.id 
FROM Weather w1 INNER JOIN Weather w2 
ON DATEDIFF(w2.recordDate, w1.recordDate) = 1 
AND w2.temperature > w1.temperature;


-- Best Solution
-- # 1.
SELECT w2.id FROM Weather w1,Weather w2
WHERE DATEDIFF(w2.recordDate, w1.recordDate) = 1 
AND w2.temperature > w1.temperature;
-- // where datediff -> date difference b/w two dates

-- # 2.
SELECT w2.id FROM Weather w1, Weather w2
WHERE w2.temperature > w1.temperature 
AND SUBDATE(w2.recordDate, 1) = w1.recordDate;
-- // where subdate -> subtract date 

-- #3.
SELECT w2.id FROM Weather w1 JOIN Weather w2
ON w2.temperature > w1.temperature 
AND DATEDIFF(w2.recordDate, w1.recordDate) = 1;