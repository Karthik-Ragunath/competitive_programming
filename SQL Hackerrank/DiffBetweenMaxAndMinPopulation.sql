select (select max(population) from city) - (select min(population) from city);
