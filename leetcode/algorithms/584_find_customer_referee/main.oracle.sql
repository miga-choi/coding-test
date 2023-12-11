-- /* Write your PL/SQL query statement below */
SELECT name
FROM Customer
WHERE NVL(referee_id, 0) <> 2;


-- /* Best Solution */
-- /* Best Solution 1 */
SELECT name
FROM Customer
WHERE referee_id != 2
    OR referee_id IS NULL;

-- /* Best Solution 2 */
SELECT name
FROM Customer
WHERE referee_id <> 2
    OR referee_id IS NULL;