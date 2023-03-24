n = list(input() for _ in range(5))
count = 0
total = 0
for i in n:
    if int(i) < 40:
        n[count] = '40'
    total += int(n[count])
    count += 1


print(total//5)