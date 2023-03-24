def min1(a, b, c):
    if a < b:
        if a < c:
            return a
        else:
            return c
    else:
        if b < c:
            return b
        else:
            return c

def min2(a, b):
    if a > b:
        return b
    else:
        return a

b1 = int(input())
b2 = int(input())
b3 = int(input())
d1 = int(input())
d2 = int(input())
print(min1(b1,b2,b3)+min2(d1,d2)-50)