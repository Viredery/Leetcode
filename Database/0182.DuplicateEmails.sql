SELECT Email
FROM (SELECT Email, Count(Email) AS Num FROM Person GROUP BY Email) As Tmp
WHERE Num > 1;