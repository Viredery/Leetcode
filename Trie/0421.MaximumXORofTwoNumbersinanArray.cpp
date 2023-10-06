class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        for (const auto& num : nums) {
            TrieNode* node = &root_;
            for (int i = 31; i >= 0; --i) {
                const int bit = (num >> i) & 1;
                node = node->CreateNextNodeIfNeeded(bit);
            }
        }

        int max_xor_num = 0;
        for (const auto& num : nums) {
            TrieNode* node = &root_;
            int current_num = 0;
            for (int i = 31; i >= 0; --i) {
                const int bit = (num >> i) & 1;
                const int reversed_bit = 1 - bit;
                TrieNode* next_node = node->GetNextNode(reversed_bit);
                if (next_node) {
                    current_num += (1 << i);
                    node = next_node;
                } else {
                    node = node->GetNextNode(bit);
                }
            }
            max_xor_num = std::max(max_xor_num, current_num);
        }
        return max_xor_num;
    }
private:
    struct TrieNode {
        TrieNode() : next(2, nullptr) {}
        ~TrieNode() {
            for (const auto* ptr : next) {
                if (ptr) {
                    delete ptr;
                }
            }
        }

        TrieNode* GetNextNode(int bit) const {
            return next[bit];
        }

        TrieNode* CreateNextNodeIfNeeded(int bit) {
            if (!next[bit]) {
                next[bit] = new TrieNode{};
            }
            return next[bit];
        }

        std::vector<TrieNode*> next;
    };

    TrieNode root_;
};
