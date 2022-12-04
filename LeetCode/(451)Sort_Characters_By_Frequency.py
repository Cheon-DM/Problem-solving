'''
' leetcode - 451
' hash table, string, sorting, priority queue, bucket sort, counting
'''

from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        freq = Counter(s)
        s_dir = list(freq.items())
        s_dir.sort(key=lambda x:(-x[1], x[0]))
        words = [alpha*n for alpha, n in s_dir]
        answer = ''.join(words)
        return answer