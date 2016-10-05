# Write your MySQL query statement below
select Scores1.Score as Score, count(distinct Scores2.Score) as Rank
from Scores as Scores1, Scores as Scores2
where Scores1.Score < Scores2.Score or (Scores1.Id = Scores2.Id)
group by Scores1.Id
order by Scores1.Score desc

select Score, (select count(distinct Score) + 1 from Scores where Score > a.Score) as Rank
from Scores as a
order by score desc
