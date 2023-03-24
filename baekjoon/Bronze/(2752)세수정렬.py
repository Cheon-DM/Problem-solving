a, b, c = map(int, input().split())


def sort(a, b, c):
    if a > b:
        if a > c:
            if b > c:
                first = a
                second = b
                third = c
            else:
                first = a
                second = c
                third = b
        else:
            first = c
            second = a
            third = b
    else:
        if b > c:
            if a > c:
                first = b
                second = a
                third = c
            else:
                first = b
                second = c
                third = a
        else:
            first = c
            second = b
            third = a

    print(third, second, first)


sort(a, b, c)
