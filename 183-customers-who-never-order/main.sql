# Write your MySQL query statement below
# use left join
select name as Customers
from Customers left join Orders
on Customers.Id = Orders.CustomerId
where Orders.CustomerId is null

# use embed select
select name as Customers
from Customers
where Id not in (select CustomerId from Orders)
