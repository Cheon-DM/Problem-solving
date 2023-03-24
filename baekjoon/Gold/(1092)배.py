# Greedy method
'''
while 모든 box가 배로 옮길 때까지:
    for i in crane 개수:
        for j in box 개수:
            if crane[i]에 box[j]를 담을 수 있음 and 아직 position[j] == 0:
                position += 1
                다음 크래인에 박스 담기
            else:
                position += 1
                다음 박스 테스트

'''

n = int(input()) # crane 수
crane = list(map(int,input().split())) # 각각 crane 무게제한
m = int(input()) # box 수
box = list(map(int,input().split())) # 각각 box 무게

# 무게순으로 내림차정렬
crane.sort(reverse=True)
box.sort(reverse=True)

chk = [0 for _ in range(m)] # box chk 0으로 초기화
box_count = 0 # box counter
position = [0 for _ in range(n)] # crane 위치 표시]
time = 0 # 걸리는 시간

if max(box) > max(crane):
    print(-1)
else:
    while box_count != m:
        for i in range(n):
            while position[i] < m:
                if crane[i] >= box[position[i]] and chk[position[i]] != 1:
                    chk[position[i]] = 1
                    position[i] += 1
                    box_count += 1
                    break
                position[i] += 1
        time += 1
    print(time)


