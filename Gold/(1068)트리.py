# dfs 이용
'''
    dfs를 이용해 해당하는 노드를 찾아낸 후 그 노드의 자식노드는 모두 없앤다
        -> 없앨 노드의 부모노드 값을 -5로 설정
    없앤 노드를 제외하고 리프노드의 개수 세기
'''

n = int(input())
parents = list(map(int,input().split()))
delete = int(input())

def dfs(k):
    parents[k] = -5
    for i in range(n):
        if parents[i] == k:
            dfs(i)

dfs(delete)
count = 0

for i in range(n):
    if parents[i] != -5 and i not in parents:
        count += 1

print(count)