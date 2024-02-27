/* Write your PL/SQL query statement below */
SELECT TO_CHAR(ACTIVITY_DATE,'YYYY-MM-DD') AS DAY,COUNT(DISTINCT USER_ID) AS ACTIVE_USERS
FROM ACTIVITY
WHERE ACTIVITY_DATE BETWEEN DATE '2019-06-28' AND DATE '2019-07-27'
GROUP BY ACTIVITY_DATE
ORDER BY ACTIVITY_DATE;