/* Write your T-SQL query statement below */
WITH CTE AS 
(
    SELECT
        x, y, z,
        IIF(x + y > z, 1, 0) c1,
        IIF(x + z > y, 1, 0) c2,
        IIF(y + z > x, 1, 0) c3
    FROM Triangle
)
SELECT x, y, z, IIF(c1 = 1 AND c2 = 1 AND C3 = 1,'Yes','No') triangle
FROM CTE;