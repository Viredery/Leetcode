# Write your MySQL query statement below
SELECT a.Name as Employee
FROM Employee a, Employee b
WHERE a.ManagerId = b.Id AND a.Salary > b.Salary;