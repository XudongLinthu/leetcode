# Write your MySQL query statement below
select Employee.Name as Employee
from Employee inner join Employee as Manager on Manager.Id = Employee.ManagerId
where Employee.Salary > Manager.Salary
