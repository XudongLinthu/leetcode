# Write your MySQL query statement below
delete p1 from Person as p1 left join Person as p2 on p1.Email = p2.Email where p1.Id > p2.Id
