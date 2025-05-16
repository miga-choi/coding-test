-- /* Write your PL/SQL query statement below */
SELECT customer_number
FROM (
        SELECT customer_number,
            DENSE_RANK() OVER(
                ORDER BY COUNT(customer_number) DESC
            ) AS D_RNK
        FROM Orders
        GROUP BY customer_number
    )
WHERE D_RNK = 1;


-- /* Solution */
-- /* Solution 1 */
SELECT customer_number
FROM Orders
GROUP BY customer_number
HAVING COUNT(DISTINCT order_number) IN (
        SELECT MAX(countn)
        FROM (
                SELECT COUNT(DISTINCT order_number) AS countn
                FROM Orders
                GROUP BY customer_number
            )
    );

-- /* Solution 2 */
SELECT customer_number
FROM (
        SELECT customer_number,
            COUNT(customer_number) AS order_count
        FROM Orders
        GROUP BY customer_number
        ORDER BY order_count DESC NULLS LAST
    )
WHERE rownum = 1;

-- /* Solution 3 */
SELECT customer_number
FROM (
        SELECT customer_number,
            COUNT(*)
        FROM Orders
        GROUP BY customer_number
        ORDER BY 2 DESC
    )
WHERE ROWNUM = 1;
