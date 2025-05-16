-- /* Write your PL/SQL query statement below */
SELECT name
FROM Customer
WHERE NVL(referee_id, 0) <> 2;


-- /* Solution */
-- /* Solution 1 */
SELECT name
FROM Customer
WHERE referee_id != 2
    OR referee_id IS NULL;

-- /* Solution 2 */
SELECT name
FROM Customer
WHERE referee_id <> 2
    OR referee_id IS NULL;
