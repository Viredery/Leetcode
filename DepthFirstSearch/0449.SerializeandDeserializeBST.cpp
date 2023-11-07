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
        if (!root) {
            return "";
        }
        std::string str = std::to_string(root->val);
        if (root->left) {
            str += "," + serialize(root->left);
        }
        if (root->right) {
            str += "," + serialize(root->right);
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return nullptr;
        }
        std::queue<int> vals = Split(data, ",");
        const int lower = std::numeric_limits<int>::min();
        const int upper = std::numeric_limits<int>::max();

        return ConstructBST(lower, upper, &vals);
    }
private:
    std::queue<int> Split(std::string_view str, std::string_view delimiter) {
        std::queue<int> output;
        size_t begin = 0;
        while (begin < str.size()) {
            const auto end = str.find_first_of(delimiter, begin);
            if (end != begin) {
                const int val = std::stoi(std::string(str.substr(begin, end - begin)));
                output.push(val);
            }
            if (end == std::string_view::npos) {
                break;
            }

            begin = end + 1;
        }

        return output;
    }

    TreeNode* ConstructBST(int lower, int upper, std::queue<int>* vals) {
        if (vals->empty() || vals->front() <= lower || vals->front() >= upper) {
            return nullptr;
        }
        const int val = vals->front();
        vals->pop();
        TreeNode* root = new TreeNode(val);
        root->left = ConstructBST(lower, val, vals);
        root->right = ConstructBST(val, upper, vals);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
