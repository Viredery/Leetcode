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
        string data;
        encode(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return decode(data, pos, INT_MIN, INT_MAX);
    }

private:
    void encode(TreeNode* root, string& data) {
        if (root == nullptr)
            return;
        char buf[4];
        memcpy(buf, &(root->val), 4);
        for (int i = 0; i < 4; i++)
            data.push_back(buf[i]);
        encode(root->left, data);
        encode(root->right, data);
    }
    
    TreeNode* decode(const string& data, int& pos, int minVal, int maxVal) {
        if (pos == data.size())
            return nullptr;
        
        int val;
        memcpy(&val, &data[pos], 4);
        if (val < minVal || val > maxVal)
            return nullptr;
        
        pos += 4;
        TreeNode* root = new TreeNode(val);
        root->left = decode(data, pos, minVal, val);
        root->right = decode(data, pos, val, maxVal);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
