'''
' Leetcode - 1704
' string, counting
'''

class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels = list('aeiouAEIOU')
        a = s[0:len(s)//2]
        b = s[len(s)//2:]
        a_count = b_count = 0
        for vowel in vowels:
            a_count += a.count(vowel)
            b_count += b.count(vowel)
        
        return a_count == b_count
        