import sys, heapq
input = sys.stdin.readline

classCount = int(input()) # class 개수

arr = [list(map(int, input().split())) for _ in range(classCount)] # class array

arr.sort(key = lambda x:x[1]) # class 시작 시간을 기준으로 sort

minClass = [] # 진행할 수 있는 최소 강의실 개수 (초기화 : 최대 강의실 개수)
classNumber = 0 # 동시간에 사용하는 class 개수

for x in arr:
    while minClass and minClass[0] <= x[1]:
        heapq.heappop(minClass)
    
    heapq.heappush(minClass, x[2])
    classNumber = max(classNumber, len(minClass))
    
print(classNumber)

# ----------------------------------------------------------- #

