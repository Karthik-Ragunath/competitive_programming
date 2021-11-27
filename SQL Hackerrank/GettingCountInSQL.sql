-- declare cnt1 int;
-- declare @cnt2 int;
-- set @cnt1 = (select count(city) from station);
-- set @cnt2 = (select count(distinct city) from station);
-- select (@cnt - @cnt2);

select (select count(city) from station) - (select count(distinct city) from station);
