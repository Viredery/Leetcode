# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        pre = head
        if pre != None:
            post = pre.next
        else:
            return False
        while post != None and post != pre:
            pre = pre.next
            post = post.next
            if post == None:
                return False
            post = post.next
        if post == None:
            return False
        return True