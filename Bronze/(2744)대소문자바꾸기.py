'''
' baekjoon - 2744
' implementation, string
'''

#input
str = input()

#sol
strlist = list(str)
result = ""

for word in strlist:
    if word.isupper():
        result += word.lower()

    else:
        result += word.upper()


print(result)