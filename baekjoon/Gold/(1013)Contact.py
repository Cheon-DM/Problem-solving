testcase = int(input())

for i in range(testcase):
    import re
    p = re.compile('(100+1+|01)+')
    tester = input()
    m = p.fullmatch(tester)
    if m:
        print('YES')
    else:
        print('NO')