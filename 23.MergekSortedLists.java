/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        Queue<ListNode> queue = new PriorityQueue<ListNode>(new Comparator<ListNode>() {
                                            public int compare(ListNode left, ListNode right) {
                                                if (left.val < right.val) return -1;
                                                if (left.val > right.val) return 1;
                                                return 0;
                                            }
                                        });
        ListNode sortedList = null, currNode = null;
        for (ListNode list : lists) {
            if (null == list)
                continue;
            queue.add(list);
        }
        
        while (!queue.isEmpty()) {
            ListNode node = queue.poll();
            if (null == sortedList) {
                currNode = sortedList = node;
            } else {
                currNode.next = node;
                currNode = currNode.next;
            }
            if (null != node.next) {
                queue.add(node.next);
            }
        }
        if (null != currNode)
            currNode.next = null;
        return sortedList;
    }
}