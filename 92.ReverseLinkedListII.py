# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        headNode = ListNode(0)
        headNode.next = head
        head = headNode
        cur, curPos = head, 0
        left, right = head, head
        while curPos + 1 < m:
            cur, curPos = cur.next, curPos + 1
        left = cur
        while curPos < n + 1:
            cur, curPos = cur.next, curPos + 1
        right = cur
        for _ in range(n - m + 1):
            node = left.next
            left.next = node.next
            node.next = right
            right = node
        left.next = right
        return head.next