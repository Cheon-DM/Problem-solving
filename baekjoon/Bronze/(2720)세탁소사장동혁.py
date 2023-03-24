testcase = int(input()) # testcase 개수

for i in range (testcase):
    coin = int(input()) # 거스름돈
    Q = coin // 25 # Quarter 개수
    coin -= (Q * 25)
    D = coin // 10 # Dime 개수
    coin -= (D * 10)
    N = coin // 5 # Nickel 개수
    coin -= (N * 5)
    P = coin # Penny 개수
    print(Q, end=' ') # print
    print(D, end=' ')
    print(N, end=' ')
    print(P)
