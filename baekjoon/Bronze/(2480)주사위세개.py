a,b,c = map(int, input().split())
def max(a, b, c):
    if a>b:
        if a>c:
            return a
        else:
            return c
    else:
        if b>c:
            return b
        else:
            return c

if a==b and b==c:
    print(10000+a*1000)
elif (a==b and b!=c):
    print(1000+a*100)
elif (a!=b and b==c):
    print(1000+b*100)
elif (a==c and a!=b):
    print(1000+a*100)
else:
    print(100*max(a,b,c))