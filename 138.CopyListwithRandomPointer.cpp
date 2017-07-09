/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr)
            return nullptr;
        RandomListNode *node = head;
        while (node) {
            RandomListNode *copyNode = new RandomListNode(node->label);
            copyNode->next = node->next;
            node->next = copyNode;
            node = copyNode->next;
        }
        node = head;
        while (node) {
            node->next->random = node->random ? node->random->next : nullptr;
            node = node->next->next;
        }
        RandomListNode *newHead = head->next;
        node = head;
        while (node) {
            RandomListNode *tmp = node->next->next;
            if (tmp)
                node->next->next = tmp->next;
            node->next = tmp;
            node = tmp;
        }
        return newHead;
    }
};