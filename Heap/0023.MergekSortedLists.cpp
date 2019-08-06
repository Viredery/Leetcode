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
        priority_queue<ListNode*, vector<ListNode*>, cmp> que;
        for (int i = 0; i != lists.size(); i++)
            if (lists[i])
                que.push(lists[i]);
        
        ListNode dummy = ListNode(0), *merged = &dummy;
        while (!que.empty()) {
            ListNode* node = que.top();
            que.pop();
            merged->next = node;
            merged = merged->next;
            if (node->next)
                que.push(node->next);
        }
        return dummy.next;
    }
private:
    struct cmp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};
