# baekjoon - 4344
# math, arithmetic

def roundTraditional(val, digits):
    return round(val+10**(-len(str(val))-1), digits)

C = int(input())

for _ in range(C):
    nums = list(map(int, input().split()))
    avg = sum(nums[1:]) / nums[0]
    
    cnt = 0
    for i in nums[1: ]:
        if avg < i:
            cnt += 1
    
    rate = cnt / nums[0] * 100
    print(f'{roundTraditional(rate, 3):.3f}%')