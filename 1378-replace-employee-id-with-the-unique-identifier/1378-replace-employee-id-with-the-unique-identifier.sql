# Write your MySQL query statement below

SELECT eu.unique_id, e.name 
# From EmployeeUNI as eu
# LEFT JOIN Employees as e
FROM employees as e
LEFT JOIN EmployeeUNI as eu
ON eu.id = e.id;