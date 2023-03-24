''' baekjoon - 2470
* sorting, binary search, pointer
'''

# input
from sys import stdin
n = int(stdin.readline())
sol = list(map(int, stdin.readline().split()))

# sort
sol.sort()

# pointer
l = 0
r = n -1

# standard
dif = 2000000000

# sol
while l < r:
    s_l = sol[l]
    s_r = sol[r]
    
    tmp = s_l + s_r
    
    if abs(tmp) < dif:
        dif = abs(tmp)
        result = [s_l, s_r]
        
    if tmp < 0:
        l += 1
    else:
        r -= 1


print(result[0], result[1])