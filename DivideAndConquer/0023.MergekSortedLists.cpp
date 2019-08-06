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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> nexts;
        while (lists.size() > 1) {
            for (int i = 0; i < lists.size(); i += 2) {
                if (i + 1 < lists.size())
                    nexts.push_back(mergeTwoLists(lists[i], lists[i + 1]));
                else
                    nexts.push_back(lists[i]);
            }
            lists = std::move(nexts);
        }
        return lists.empty() ? nullptr : lists[0];
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head = ListNode(0), *node = &head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                node->next = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        node->next = l1 ? l1 : l2;
        return head.next;
    }
};
