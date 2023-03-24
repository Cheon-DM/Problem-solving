'''
' baekjoon - 10872
' math, implementation, combination
'''

#input
N = int(input())

#sol
result = 1
for i in range (1, N+1):
    result *= i

print(result)