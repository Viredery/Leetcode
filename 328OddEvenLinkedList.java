/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode oddEvenList(ListNode head) {
        ListNode listOdd = new ListNode(0);
        ListNode listEven = new ListNode(0);
        ListNode pOdd = listOdd, pEven = listEven, pCurrent = head;
        while (pCurrent != null) {
            pOdd.next = pCurrent;
            pOdd = pOdd.next;
            pCurrent = pCurrent.next;
            if (pCurrent == null)
                break;
            pEven.next = pCurrent;
            pEven = pEven.next;
            pCurrent = pCurrent.next;
        }
        pEven.next = null;
        pOdd.next = listEven.next;
        return listOdd.next;
    }
}