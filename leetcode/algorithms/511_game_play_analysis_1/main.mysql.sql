-- # Write your MySQL query statement below
SELECT player_id,
    MIN(event_date) AS first_login
FROM Activity
GROUP BY player_id;


-- Best Solution
select player_id,
    min(event_date) as first_login
from activity
group by player_id