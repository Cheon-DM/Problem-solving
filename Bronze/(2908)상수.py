a, b = input().split()
rev_a = [0 for _ in range(3)]
rev_b = [0 for _ in range(3)]
for i in range (3):
    rev_a[i] = a[2-i]
    rev_b[i] = b[2-i]

if ''.join(rev_a) > ''.join(rev_b):
    print(''.join(rev_a))
else:
    print(''.join(rev_b))