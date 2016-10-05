# Write your MySQL query statement below
select WeatherToday.Id as Id
from Weather as WeatherToday inner join Weather as WeatherYesterday
on DATEDIFF(WeatherToday.Date, WeatherYesterday.Date) = 1
where WeatherToday.Temperature > WeatherYesterday.Temperature
