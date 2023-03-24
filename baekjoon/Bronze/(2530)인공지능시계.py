h, m, s = map(int, input().split())
x = int(input())

s += x % 60
x = x // 60
if s >= 60:
    m += 1
    s -= 60

m += x % 60
x = x // 60
if m >= 60:
    h += 1
    m -= 60

h += x % 24
if h >= 24:
    h -= 24

print(h, m, s)