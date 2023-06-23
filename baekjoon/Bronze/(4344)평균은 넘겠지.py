# baekjoon - 4344
# math, arithmetic

C = int(input())

for _ in range(C):
    nums = list(map(int, input().split()))
    avg = sum(nums[1:]) / nums[0]
    
    cnt = 0
    for i in nums[1: ]:
        if avg < i:
            cnt += 1
    
    rate = cnt / nums[0] * 100
    print(f'{rate:.3f}%')