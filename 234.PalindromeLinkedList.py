# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
        
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        slow = fast = head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
        newHead = None
        while slow:
            tmp = slow.next
            slow.next = newHead
            newHead = slow
            slow = tmp
        while newHead is not None:
            if head.val != newHead.val:
                return False
            head, newHead = head.next, newHead.next
        return True