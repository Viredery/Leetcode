/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode leftNode = null, rightNode = head;
        for (int i = 0; i != n; i++) {
            if (null == rightNode)
                break;
            rightNode = rightNode.next;
        }
        if (null != rightNode) {
            leftNode = head;
            rightNode = rightNode.next;
        } else
            return head.next;
        while (null != rightNode) {
            rightNode = rightNode.next;
            leftNode = leftNode.next;
        }
        leftNode.next = leftNode.next.next;
        return head;
    }
}