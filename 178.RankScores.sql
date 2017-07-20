SELECT Score, (SELECT COUNT(DISTINCT Score) FROM Scores WHERE Score >= s.Score) AS Rank
FROM Scores s ORDER BY Rank;