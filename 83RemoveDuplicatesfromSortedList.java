/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null)
            return head;
        int prev = head.val;
        ListNode node = head;
        while (node.next != null) {
            if (prev == node.next.val) {
                node.next = node.next.next;
            } else {
                node = node.next;
                prev = node.val;
            }
        }
        return head;
    }
}