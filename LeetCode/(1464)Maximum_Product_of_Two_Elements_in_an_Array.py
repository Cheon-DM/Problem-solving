'''
' Leetcode - 1464
' array, sorting, heap, priority queue
'''

from queue import PriorityQueue

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        pq = PriorityQueue()
        for i in nums:
            pq.put((-i, i))
        
        a = pq.get()[1]-1
        b = pq.get()[1]-1
        
        return a*b