-- /* Write your PL/SQL query statement below */
SELECT name, population, area
FROM World
WHERE area >= 3000000
    OR population >= 25000000;


-- /* Solution */
-- /* Solution 1: OR */
SELECT name, population, area
FROM World
WHERE area >= 3000000
    OR population >= 25000000;

-- /* Solution 2: Union */
SELECT name, population, area
FROM World
WHERE area >= 3000000
UNION
SELECT name, population, area
FROM World
WHERE population >= 25000000;
