''' baekjoon - 2751
* sorting 
'''

# input
from sys import stdin
n = int(stdin.readline())
numList = [0] * n
for i in range(n):
    numList[i] = int(stdin.readline())
    
# sol
numList.sort()
for a in numList:
    print(a)