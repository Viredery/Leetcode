/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if (null == head)
            return null;
        ListNode prev = null, curr = head, next = head;
        while((next = next.next) != null) {
            if (next.next != null) {
                next = next.next;
                curr.next.next = curr;
                if (null == prev)
                    head = curr.next;
                else
                    prev.next = curr.next;
                curr.next = next;
                prev = curr;
                curr = next;
            } else {
                if (null == prev)
                    head = next;
                else
                    prev.next = next;
                next.next = curr;
                curr.next = null;
                break;
            }
        }
        return head;
    }
}