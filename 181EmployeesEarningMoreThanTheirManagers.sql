# Write your MySQL query statement below
SELECT Tmp1.Name AS Employee
FROM Employee AS Tmp1, Employee AS Tmp2
WHERE Tmp1.ManagerId = Tmp2.Id and Tmp1.Salary > Tmp2.Salary;