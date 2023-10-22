/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* one, const ListNode* other) {
            return one->val > other->val;
        };
        std::priority_queue<const ListNode*, std::vector<const ListNode*>, decltype(cmp)> pq(cmp);
        for (const auto* list : lists) {
            if (!list) {
                continue;
            }
            pq.push(list);
        }
        ListNode dummy{0, nullptr};
        ListNode* ptr = &dummy;
        while (!pq.empty()) {
            const ListNode* head = pq.top();
            pq.pop();
            ptr->next = new ListNode{head->val, nullptr};
            ptr = ptr->next;
            if (head->next) {
                pq.push(head->next);
            }
        }
        return dummy.next;
    }
};
