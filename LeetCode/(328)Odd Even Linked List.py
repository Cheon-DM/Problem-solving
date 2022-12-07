'''
' leetcode - 328
' linked list
'''

class Solution:
    def listNodeCountLen(self, linkedList: Optional[ListNode]) -> int:
        tmp = linkedList
        idx = 0
        while tmp:
            tmp = tmp.next
            idx += 1
        return idx

    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        length = self.listNodeCountLen(head)
        if (length == 0 or length == 1):
            return head
        elif (length % 2 == 0):
            mid = length // 2 - 1;
        else :
            mid = length // 2
        
        answer = ListNode()
        cur = answer
        p = head
        cur.val = p.val
        while mid:            
            p = p.next.next
            cur.next = ListNode(p.val)
            cur = cur.next
            mid -= 1
        
        mid = (length // 2) - 1
        p = head.next
        cur.next = ListNode(p.val)
        cur = cur.next
        while mid:
            p = p.next.next
            cur.next = ListNode(p.val)
            cur = cur.next
            mid -= 1
        
        return answer