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
            return "#";
        }
        return std::to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::vector<std::string_view> nums = Split(data, ",");
        int cur_pos = 0;
        return ConstructBinaryTree(nums, &cur_pos);
    }

private:
    TreeNode* ConstructBinaryTree(const std::vector<std::string_view>& nums, int* cur_pos) const {
        if (nums[*cur_pos] == "#") {
            ++(*cur_pos);
            return nullptr;
        }
        const int val = std::stoi(std::string(nums[*cur_pos]));
        TreeNode* root = new TreeNode(val);
        ++(*cur_pos);
        root->left = ConstructBinaryTree(nums, cur_pos);
        root->right = ConstructBinaryTree(nums, cur_pos);
        return root;
    }

    std::vector<std::string_view> Split(std::string_view str, std::string_view delimiter) {
        std::vector<std::string_view> output;
        size_t begin = 0;
        while (begin < str.size()) {
            const auto end = str.find_first_of(delimiter, begin);
            if (end != begin) {
                output.emplace_back(str.substr(begin, end - begin));
            }
            if (end == std::string_view::npos) {
                break;
            }

            begin = end + 1;
        }

        return output;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
