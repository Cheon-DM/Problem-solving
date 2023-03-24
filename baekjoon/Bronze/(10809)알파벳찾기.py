words = input()
cnt_alphabet = list(range(97, 123)) # a ~ z

for x in cnt_alphabet:
    print(words.find(chr(x)))