class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> dict;
        for (const auto num : nums) {
            if (dict.count(num)) {
                return true;
            }
            dict.insert(num);
        }
        return false;
    }
};
