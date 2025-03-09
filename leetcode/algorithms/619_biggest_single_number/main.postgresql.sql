-- Write your PostgreSQL query statement below
SELECT MAX(num) AS num
FROM (
  SELECT num
  FROM MyNumbers
  GROUP BY num 
  HAVING COUNT(num) = 1
);

-- Solution
SELECT
  CASE
    WHEN COUNT(num)=1 THEN num
    ELSE NULL
  END AS num
FROM MyNumbers
GROUP BY num
ORDER BY 1 DESC NULLS LAST
LIMIT 1;
