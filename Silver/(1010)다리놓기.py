case = int(input())

import math

def nCr(n, r):
    if n < 1 or r < 0 or n < r:
        raise Exception('error')
    r = min(r, n-r)
    print(math.factorial(n)//(math.factorial(r)*math.factorial(n-r)))
    

while case > 0:
    N, M = map(int, input().split())
    nCr(M, N)
    case -= 1
