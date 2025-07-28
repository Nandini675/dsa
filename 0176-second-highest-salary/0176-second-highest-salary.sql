# Write your MySQL query statement below
 select ( select distinct e.salary 
  from        Employee as e
  order by e.salary desc
  limit 1  offset 1) as   SecondHighestSalary