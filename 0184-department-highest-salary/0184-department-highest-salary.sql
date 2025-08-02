# Write your MySQL query statement below
select  d.name as Department  ,e.name as Employee  ,e.salary  from Employee as e
join Department as d
on d.id=e.departmentId

where e.salary=( 

     select max(e.salary) from Employee as e where
d.id=e.departmentId
);
