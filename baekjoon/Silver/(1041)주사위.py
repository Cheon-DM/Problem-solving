n = int(input())
l = list(map(int,input().split()))
if n == 1:
    l.sort()
    print(l[0]+l[1]+l[2]+l[3]+l[4])
else:
    minimal = []
    minimal.append(min(l[0], l[5]))
    minimal.append(min(l[1], l[4]))
    minimal.append(min(l[2], l[3]))
    minimal.sort()
    three = 4*(minimal[0]+minimal[1]+minimal[2])
    one = (5*(n**2)-(16*n)+12)*minimal[0]
    two = (4*(n-1)+4*(n-2))*(minimal[0]+minimal[1])
    print(one+two+three)