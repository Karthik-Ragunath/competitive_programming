set @v1 = (select min(length(city)) from station);
set @v2 = (select city from station where length(city) = @v1 order by city limit 1);
set @v3 = (select max(length(city)) from station);
set @v4 = (select city from station where length(city) = @v3 order by city limit 1);
select @v2, @v1;
select @v4, @v3;
