testcase = int(input())

for i in range(testcase):
    price = float(input())
    print("${:.2f}".format(round(price*0.8,2)))