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
        if (lists.empty()) {
            return nullptr;
        }
        return Partion(lists, 0, lists.size() - 1);
    }
private:
    ListNode* Partion(const vector<ListNode*>& lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }
        const int mid = left + (right - left) / 2;
        ListNode* list1 = Partion(lists, left, mid);
        ListNode* list2 = Partion(lists, mid + 1, right);
        return Merge(list1, list2);
    }

    ListNode* Merge(ListNode* one, ListNode* other) {
        if (!one) {
            return other;
        }
        if (!other) {
            return one;
        }
        if (one->val <= other->val) {
            one->next = Merge(one->next, other);
            return one;
        } else {
            other->next = Merge(one, other->next);
            return other;
        }
    }
};
