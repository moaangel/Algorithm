-- 코드를 입력하세요
SELECT B.TITLE, B.BOARD_ID, R.REPLY_ID, R.WRITER_ID, R.CONTENTS, DATE_FORMAT(R.CREATED_DATE, '%Y-%m-%d') as CREATED_DATE
from USED_GOODS_BOARD B
INNER JOIN USED_GOODS_REPLY R on B.BOARD_ID = R.BOARD_ID
WHERE year(B.CREATED_DATE) = 2022
and month(B.CREATED_DATE) = 10
ORDER BY CREATED_DATE asc, TITLE asc