-- /* Write your T-SQL query statement below */
SELECT name
FROM Customer
WHERE ISNULL(referee_id, 0) <> 2;


-- /* Solution */
SELECT name
FROM Customer
WHERE referee_id IS NULL
    OR referee_id <> 2;
