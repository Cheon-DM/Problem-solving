words = input().upper() # 대문자로 변환
wordSet = list(set(words)) # 단어 문자 Set
cnt_word = []
for i in wordSet :
    cnt = words.count(i)
    cnt_word.append(cnt)
    
if cnt_word.count(max(cnt_word)) > 1 :
    print('?')
else :
    maxIndex = cnt_word.index(max(cnt_word))
    print(wordSet[maxIndex])