/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        Node* ptr = head;
        while (ptr) {
            Node* new_ptr = new Node(ptr->val);
            new_ptr->next = ptr->next;
            ptr->next = new_ptr;
            ptr = new_ptr->next;
        }
        ptr = head;
        while (ptr) {
            ptr->next->random = ptr->random ? ptr->random->next : nullptr;
            ptr = ptr->next->next;
        }
        ptr = head;
        Node dummy(0);
        Node* new_ptr = &dummy;
        while (ptr) {
            new_ptr->next = ptr->next;
            ptr->next = ptr->next->next;
            ptr = ptr->next;
            new_ptr = new_ptr->next;
        }
        return dummy.next;
    }
};

