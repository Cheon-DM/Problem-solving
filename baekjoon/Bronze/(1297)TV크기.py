diagonal, height, width = map(int, input().split())
multi = diagonal/((height**2 + width**2)**0.5)
print(int(multi*height), int(multi*width))