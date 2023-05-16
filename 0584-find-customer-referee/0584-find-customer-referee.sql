# # Write your MySQL query statement below
# SELECT name
# FROM Customer
# Where  referee_id is null || referee_id != 2;

# three values logic in my SQL : True, false & unknown
# NULL values in a table are under unkown logic. hence a Null check is required







SELECT name from Customer where referee_id IS NULL || referee_id != 2;