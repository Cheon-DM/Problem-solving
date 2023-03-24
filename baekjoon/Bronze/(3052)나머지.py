nums = [int(input()) for _ in range(10)]
remain = [0 for _ in range(10)]
for i in range(10):
    remain[i] = nums[i] % 42

set_remain = set(remain)
print(len(set_remain))