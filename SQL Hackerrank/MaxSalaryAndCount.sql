select salary * months, count(*) from employee where salary * months = (select max(salary * months) from employee) group by (salary * months);
