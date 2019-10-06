/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node* node = root;
        while (node) {
            Node dummyNode(0, nullptr, nullptr, nullptr), *curNode;
            curNode = &dummyNode;
            while (node) {
                if (node->left) {
                    curNode->next = node->left;
                    curNode = curNode->next;
                }
                if (node->right) {
                    curNode->next = node->right;
                    curNode = curNode->next;
                }
                node = node->next;
            }
            node = dummyNode.next;
        }
        return root;
    }
};
