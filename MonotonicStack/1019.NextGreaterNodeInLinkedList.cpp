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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> next_larger_values;
        std::stack<std::pair<int, int>> st;
        int i = 0;
        while (head) {
            while (!st.empty() && st.top().first < head->val) {
                next_larger_values[st.top().second] = head->val;
                st.pop();
            }
            next_larger_values.push_back(0);
            st.emplace(head->val, i++);
            head = head->next;
        }
        return next_larger_values;
    }
};
