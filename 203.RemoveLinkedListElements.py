# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        node = ListNode(-1)
        node.next = head
        head = node
        
        cur = head
        while cur.next:
            if cur.next.val != val:
                cur = cur.next
            else:
                cur.next = cur.next.next
        return head.next