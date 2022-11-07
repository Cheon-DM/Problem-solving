'''
' baekjoon - 14681
' implementation, geometry
'''

#input
x = int(input())
y = int(input())

#sol
if (x > 0 and y > 0):
    print(1)
elif (x < 0 and y > 0):
    print(2)
elif (x < 0 and y < 0):
    print(3)
elif (x > 0 and y < 0):
    print(4)