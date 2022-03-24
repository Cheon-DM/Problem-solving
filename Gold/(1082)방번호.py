""" M원을 모두 사용해 숫자 구매, 0 ~ N-1까지의 숫자 존재, 각 숫자 i의 가격 P_i
** 알고리즘 **
1. 0을 제외한 가장 가격이 낮고 숫자가 큰 것을 고름
2. 남은 돈으로 가장 큰 숫자를 구매
3. 남은 돈으로 구매한 것이 존재한다면 그것을 맨 앞으로 놓기, 아니면 맨 뒤
"""

import sys, math
input = sys.stdin.readline

# input
N = int(input()) # 0 ~ N-1까지 숫자
arr = list(map(int, input().split())) # 숫자 가격이 적혀 있는 array
M = int(input()) # M원까지 사용 가능

minIndex = 10 # 가격이 가장 작은 index
index = 0 # loop에 이용할 index

# 가격이 가장 싼 가장 큰 index
for x in arr:
    if minIndex >= x:
        minIndex = index
    index += 1

num = M // arr[minIndex] # 사용할 숫자 개수
restMoney = M - (num * arr[minIndex]) # 남은 돈

# 가격이 가장 싼 index가 0인 경우
secondIndex = 10 # 가격이 두 번째로 작은 index
index = 0 # loop에 이용할 index
if minIndex == 0:    
    for x in arr:
        if index == 0:
            index += 1
            continue
    
        if secondIndex >= x:
            secondIndex = index
        index += 1

restMoney += arr[minIndex] * math.ceil(arr[secondIndex] / arr[minIndex])
num -= math.ceil(arr[secondIndex] / arr[minIndex])
    
restMoney -= arr[secondIndex]
thirdIndex = 10

# 역순으로 restMoney에 들어올 수 있는 가장 큰 숫자 구하기
index = 0
for i in arr:
    if restMoney <= i:
        thirdIndex = index
    index += 1