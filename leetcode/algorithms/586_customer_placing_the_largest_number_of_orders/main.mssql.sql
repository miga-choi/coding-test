-- /* Write your T-SQL query statement below */
SELECT sub.customer_number AS customer_number
FROM (
        SELECT customer_number,
            DENSE_RANK() OVER(
                ORDER BY COUNT(customer_number) DESC
            ) AS D_RNK
        FROM Orders
        GROUP BY customer_number
    ) sub
WHERE sub.D_RNK = 1;


-- /* Solution */
SELECT TOP 1 customer_number
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(customer_number) DESC
