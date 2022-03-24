sum, dif = map(int,input().split())

if sum + dif < 0 or sum - dif < 0 or (sum + dif) % 2:
    print(-1)
else:
    a= (sum+dif) //2
    b= sum - a
    print(a, b)