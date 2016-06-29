ELECT Email FROM
    (SELECT Email, COUNT(Email) AS Number FROM Person GROUP BY Email) AS TableTmp
    WHERE TableTmp.Number > 1;
