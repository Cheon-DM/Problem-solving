sec = int(input())
A = 0
B = 0
C = 0

if sec % 10 != 0:
    print(-1)

else:
    while sec >= 300:
        A += 1
        sec -= 300

    while sec >= 60:
        B += 1
        sec -= 60

    while sec >= 10:
        C += 1
        sec -= 10

    print(A, B, C)
