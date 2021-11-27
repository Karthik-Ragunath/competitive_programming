/*
Enter your query here.
*/
select concat(name, concat('(', concat(substring(occupation, 1, 1), ')'))) from occupations order by name asc;
select concat('There are a total of ', concat(count(occupation), concat(' ', concat(lower(occupation), 's.')))) from occupations group by occupation order by count(occupation), occupation asc;
