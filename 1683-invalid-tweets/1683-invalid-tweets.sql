# Write your MySQL query statement below

SELECT tweet_id 
from Tweets
where char_LENGTH(content)> 15; 