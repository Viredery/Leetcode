/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode *> arr;
        if (root == nullptr) return;
        arr.push(root);
        TreeLinkNode *preNode = nullptr;
        while (!arr.empty()) {
            int n = arr.size();
            if (preNode != nullptr)
                preNode->next = nullptr;
            for (int i = 0; i != n; i++) {
                TreeLinkNode *node = arr.front();
                arr.pop();
                if (node->left)
                    arr.push(node->left);
                if (node->right)
                    arr.push(node->right);
                if (i == 0)
                    preNode = node;
                else {
                    preNode->next = node;
                    preNode = node;
                }
            }
        }
    }
};
