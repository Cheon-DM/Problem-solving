n = int(input())

# 피보나치 수열과 같은 방식
a, b = 1, 1
for _ in range (n):
    a, b = b, (a+b)%10

print(a)