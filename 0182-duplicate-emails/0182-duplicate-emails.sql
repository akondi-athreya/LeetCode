# Write your MySQL query statement below
SELECT email from person GROUP BY email HAVING COUNT(email) > 1;