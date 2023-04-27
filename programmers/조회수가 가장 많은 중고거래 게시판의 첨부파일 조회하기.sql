-- programmers - 조회수가 가장 많은 중고거래 게시판의 첨부파일 조회하기
-- set 변수, concat

SET @path := "/home/grep/src/";

SELECT CONCAT(@path, A.BOARD_ID, "/", FILE_ID, FILE_NAME, FILE_EXT) AS FILE_PATH
FROM USED_GOODS_FILE A
JOIN (SELECT BOARD_ID
    FROM USED_GOODS_BOARD
    ORDER BY VIEWS DESC
    LIMIT 1) AS B
ON A.BOARD_ID = B.BOARD_ID
ORDER BY A.FILE_ID DESC