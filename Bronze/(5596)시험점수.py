a1, a2, a3, a4 = map(int, input().split())
b1, b2, b3, b4 = map(int, input().split())
a_total = a1+a2+a3+a4
b_total = b1+b2+b3+b4
if a_total >= b_total:
    print(a_total)
else:
    print(b_total)