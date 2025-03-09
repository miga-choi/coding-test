/* Write your T-SQL query statement below */
SELECT MAX(num) AS num
FROM (
  SELECT num
  FROM MyNumbers
  GROUP BY num 
  HAVING COUNT(num) = 1
);

-- Solution
SELECT COALESCE ((
  SELECT TOP 1 num FROM MyNumbers
  GROUP BY num
  having count(num) = 1
  ORDER BY num DESC
), NULL) AS num;
