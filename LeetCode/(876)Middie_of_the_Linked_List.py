'''
' leetcode - 876
' linked list, two pointers
'''

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        answer = head
        idx = 0
        while head:
            head = head.next
            idx += 1
        mid = idx // 2
        while mid:
            answer = answer.next
            mid -= 1
        return answer