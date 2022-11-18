# Write your MySQL query statement below

# IF(condition, value_if_true, value_if_false)

select employee_id,
 if(employee_id%2 != 0 and name not like 'M%', salary,0) as bonus
 from Employees
 order by employee_id;