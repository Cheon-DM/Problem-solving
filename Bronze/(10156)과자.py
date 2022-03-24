cost, n, money = map(int, input().split())
if cost*n <= money:
    print(0)
else:
    print(cost*n - money)