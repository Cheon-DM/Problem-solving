-- programmers - 카테고리 별 도서 판매량 집계하기
-- group by, month, join

SELECT CATEGORY, SUM(SALES) AS TOTAL_SALES
FROM BOOK A 
JOIN (SELECT BOOK_ID, SALES
FROM BOOK_SALES
WHERE MONTH(SALES_DATE) = '01') AS B
ON A.BOOK_ID = B.BOOK_ID
GROUP BY CATEGORY
ORDER BY CATEGORY