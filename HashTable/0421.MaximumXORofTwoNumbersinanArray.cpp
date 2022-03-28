class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            std::unordered_set<int> prefixes;
            for (const auto& num : nums) {
                prefixes.insert(num & mask);
            }
            const int potential_prefix_max = max | (1 << i);
            for (const auto& prefix : prefixes) {
                if (prefixes.count(potential_prefix_max ^ prefix)) {
                    max = potential_prefix_max;
                    break;
                }
            }
        }
        return max;
    }
};
