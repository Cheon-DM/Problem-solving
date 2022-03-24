""" N개의 달걀, M명의 고객
각 고객은 2개까지만 달걀 구매 가능
i번째 고객이 제시한 가격 = P_i
** 알고리즘 순서 **
1. M명의 고객이 제시한 P_i를 정렬
2. 가장 적은 가격 순으로 가격을 책정하여 이율 계산
3. 최대 2개까지만 구매 가능함을 명시
4. 이율이 커졌다면 값을 다시 저장해줌
"""

import sys
input = sys.stdin.readline

egg, line = map(int, input().split()) # 달걀 개수
customer = []
for i in range (line):
    customer.append(int(input())) # customer가 제시한 달걀 가격
customer.sort() # customer가 제시한 달걀 가격 정렬

profit = 0 # 이윤
finalEggcost = 0 # 최종 달걀 가격

for x in customer:
    eggcost = x # 달걀 가격 지정
    cost = 0 # 지정된 달걀 가격으로 판 수익
    eggcount = 0 # 세야할 달걀 개수
    
    for y in customer: # 달걀 팔 수 있음
        if eggcount == egg: break # 달걀 다 팜
        
        if eggcost <= y:
            eggcount += 1
            cost += eggcost
    
    if profit < cost: # 지금 가격이 원래 profit보다 큰 경우
        profit = cost
        finalEggcost = eggcost
        
print(finalEggcost, end=' ')
print(profit)