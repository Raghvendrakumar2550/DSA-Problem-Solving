# Write your MySQL query statement below
select e.name as Employee from Employee e Left Join Employee M
on e.managerId = M.id where e.salary > M.salary;