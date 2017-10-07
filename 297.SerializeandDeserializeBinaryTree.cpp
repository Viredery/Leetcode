/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "[";
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            if (node == nullptr) {
                res += "null,";
            } else {
                res += to_string(node->val) + ",";
                que.push(node->left);
                que.push(node->right);
            }
        }
        return res.substr(0, res.size() - 1) + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        queue<TreeNode**> que;
        que.push(&root);
        size_t start = 1, end = data.find_first_of(",]", start);
        while (start < data.size() && end != string::npos) {
            string val = data.substr(start, end-start);
            if (val == "null") {
                *que.front() = nullptr;
            } else {
                *que.front() = new TreeNode(stoi(val));
                que.push(&(*que.front())->left);
                que.push(&(*que.front())->right);
            }
            que.pop();
            start = end + 1;
            end = data.find_first_of(",]", start);
        }
        return root;
    }
};
