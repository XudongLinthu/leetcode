# Write your MySQL query statement below
select Department.Name as Department, Employee.Name as Employee, Employee.Salary as Salary
from Employee inner join Department
on Employee.DepartmentId = Department.Id
where Employee.Salary = (
    select max(Salary) from Employee
    where Employee.DepartmentId = Department.Id
)

# This one is much faster
select Department.Name as Department, Employee.Name as Employee, Employee.Salary as Salary
from Employee, Department, (
    select DepartmentId, max(Salary) as Salary from Employee group by DepartmentId
) as MaxSalary
where Employee.DepartmentId = Department.Id
    and Employee.DepartmentId = MaxSalary.DepartmentId
    and Employee.Salary = MaxSalary.Salary
