-- # Write your MySQL query statement below
SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(customer_number) DESC
LIMIT 1;


-- # Solution
-- # Solution 1
SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(customer_number) DESC
LIMIT 1;

-- # Solution 2
SELECT customer_number
FROM Orders
GROUP BY customer_number
HAVING COUNT(order_number) = (
        SELECT COUNT(order_number) cnt
        FROM Orders
        GROUP BY customer_number
        ORDER BY cnt DESC
        LIMIT 1
    );

-- # Solution 3
SELECT sub.cust AS customer_number
FROM (
        SELECT customer_number AS cust,
            COUNT(*) AS 'customer_number'
        FROM Orders
        GROUP BY customer_number
        ORDER BY customer_number DESC
        LIMIT 1
    ) AS sub;

-- # Solution 4
SELECT customer_number
FROM (
        SELECT customer_number,
            DENSE_RANK() OVER (
                ORDER BY cnt DESC
            ) AS ranking
        FROM (
                SELECT customer_number,
                    COUNT(customer_number) AS cnt
                FROM Orders
                GROUP BY customer_number
            ) sub1
    ) sub2
WHERE sub2.ranking = 1;

-- # Solution 5
SELECT customer_number
FROM Orders
GROUP BY customer_number
HAVING COUNT(order_number) = (
        SELECT COUNT(*) AS cnt
        FROM Orders
        GROUP BY customer_number
        ORDER BY cnt DESC
        LIMIT 1
    );
