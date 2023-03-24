hex = input()
hex_length = len(hex)
i = hex_length
j = 0
ten = 0
while i > 0:
    if i == hex_length:
        hex_exp = 1
    else:
        hex_exp = hex_exp * 16

    if hex[i-1] == 'A':
        ten = ten + 10*hex_exp
    elif hex[i-1] == 'B':
        ten = ten + 11*hex_exp
    elif hex[i-1] == 'C':
        ten = ten + 12*hex_exp
    elif hex[i-1] == 'D':
        ten = ten + 13*hex_exp
    elif hex[i-1] == 'E':
        ten = ten + 14*hex_exp
    elif hex[i-1] == 'F':
        ten = ten + 15*hex_exp
    else:
        ten = ten + (int(hex[i-1]))*hex_exp

    i = i - 1
    j = j + 1

print(ten)