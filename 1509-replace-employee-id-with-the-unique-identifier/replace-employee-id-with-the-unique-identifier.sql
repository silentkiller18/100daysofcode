# Write your MySQL query statement below
select 
EmployeeUNI.unique_id,EMployees.name
FROM Employees
Left join EmployeeUNI on Employees.id =EmployeeUNI.id