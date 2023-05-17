# Write your MySQL query statement below

SELECT P.product_name, S.year, S.price
from Sales as S
LEFT Join Product as P
ON P.product_id = S.product_id;