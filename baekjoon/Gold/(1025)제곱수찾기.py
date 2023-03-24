n,m = map(int, input().split())
table = []
for _ in range(n):
    table.append(input())

import math
ans = -1


for row in range(n): # 행
    for col in range(m): # 열
        for row_dif in range(-n, n): # 행의 공차
            for col_dif in range(-m, m): # 열의 공차
                if row_dif == 0 and col_dif == 0: # 행과 열이 모두 공차가 0인 경우 무한 발생
                    continue

                num = []
                r = row
                c = col

                while (0 <= r < n) and (0 <= c < m):
                    num.append(table[r][c])
                    value = math.sqrt(int("".join(num)))
                    
                    if value == int(value):
                        ans = max(ans, int(value)**2) # 최대값
                    
                    r += row_dif # 행의 공차 더해줌
                    c += col_dif # 열의 공차 더해줌

print(ans)