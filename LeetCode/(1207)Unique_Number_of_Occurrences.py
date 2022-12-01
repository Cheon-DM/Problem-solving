'''
' Leetcode - 1207
' array, hash table
'''

from collections import Counter

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        arr_len = len(set(arr))
        feq_len = len(set(Counter(arr).values()))
        return arr_len == feq_len