# Write your MySQL query statement below
# SELECT name,population,area
# FROM World
# WHERE population>=25000000 OR area>=3000000;

SELECT name, population, area
from World
Where area >= 3000000 || population >= 25000000;
