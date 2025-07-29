# Write your MySQL query statement below
select  
q.query_name , round(sum(q.rating /q.position)/count(q.query_name),2) as quality,
round(sum( case when q.rating <3 then 1 else 0 end)*100/ count(q.query_name) ,2)  as poor_query_percentage
-- -- ✅ 1. CASE WHEN q.rating < 3 THEN 1 ELSE 0 END
-- This is a conditional expression.

-- For each row:

-- If rating < 3, it gives 1 (indicating a "poor" rating).

-- Otherwise, it gives 0.

-- So it produces a virtual column like:

-- ini
-- Copy
-- Edit
-- rating   =>   CASE Output
--   5       =>       0  
--   2       =>       1  
--   4       =>       0  
--   1       =>       1  
-- ✅ 2. SUM(...)
-- Adds up all the 1s from the CASE expression.

-- So it counts how many rows had rating < 3.
from Queries as q
group by q.query_name