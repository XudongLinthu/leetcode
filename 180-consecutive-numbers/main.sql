# Write your MySQL query statement below
select distinct Logs1.Num as ConsecutiveNums
from Logs as Logs1, Logs as Logs2, Logs as Logs3
where (Logs1.Num = Logs2.Num and Logs2.Num = Logs3.Num)
    and (Logs1.Id + 1 = Logs2.Id and Logs2.Id + 1 = Logs3.Id)
