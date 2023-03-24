'''
' baekjoon - 10807
' implementation
'''

#input
N = int(input())
list = list(map(int, input().split()))
v = int(input())

#sol
result = list.count(v)
print(result)