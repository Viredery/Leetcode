/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode newHead = head;
        if (head == null)
            return newHead;
        ListNode pNode = head.next;
        newHead.next = null;
        while (pNode != null) {
            ListNode pNextNode = pNode.next;
            pNode.next = newHead;
            newHead = pNode;
            pNode = pNextNode;
        }
        return newHead;
    }
}