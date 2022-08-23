a = int(input())
b = int(input())
c = int(input())

result = str(a*b*c)
abc_list_set = list(set(result))
cnt_num = [0 for _ in range(10)]
for x in abc_list_set:
    cnt = result.count(x)
    cnt_num[int(x)] = cnt

for i in cnt_num:
    print(i)