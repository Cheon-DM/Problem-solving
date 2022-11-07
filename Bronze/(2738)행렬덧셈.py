'''
' baekjoon - 2738
' math, implementation
'''

#input
N, M = map(int, input().split())
arr1 = [list(map(int, input().split())) for _ in range(N)]
arr2 = [list(map(int, input().split())) for _ in range(N)]

#sol
result = [[0] * M] * N
for i in range(N):
    for j in range(M):
        result[i][j] = arr1[i][j] + arr2[i][j]
        print(result[i][j], end=" ")
    print("")