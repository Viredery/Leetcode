class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        for (int i = 31; i >= 0; i--) {
            unordered_set<int> s;
            mask |= 1 << i;
            for (auto num : nums)
                s.insert(mask & num);
            
            int tmp = max | (1 << i);
            for (auto num : s)
                if (s.find(tmp ^ num) != s.end())
                    max = tmp;
        }
        return max;
    }
};
