/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newHead = new ListNode(0);
        ListNode *startNode = newHead, *endNode = newHead;
        while (true) {
            ListNode *nextSegmentNode = head;
            int i;
            for (i = 0; i != k; i++) {
        	    if (NULL != nextSegmentNode) {
        		    nextSegmentNode = nextSegmentNode->next;
        	    } else
        	        break;
            }
            if (i != k) {
            	startNode->next = head;
        	    return newHead->next;
            }
            while (head != nextSegmentNode) {
        	    ListNode *nextNode = head->next;
        	    if (endNode == startNode) {
        		    endNode = head;
        		    endNode->next = NULL;
        	    }
        	    head->next = startNode->next;
        	    startNode->next = head;
        	    head = nextNode;
            }
            startNode = endNode;
        }
    }
};