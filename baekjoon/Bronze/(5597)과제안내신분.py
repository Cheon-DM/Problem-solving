'''
' baekjoon - 5597
' implementation
'''

# input & sol
studentList = list(range(1, 31))

for i in range(28):
    num = int(input())
    if num in studentList:
        studentList.remove(num)

print(studentList[0])
print(studentList[1])