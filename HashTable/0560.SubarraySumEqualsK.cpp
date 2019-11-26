class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        vector<int> sums(nums);
        for (int i = 1; i != nums.size(); i++)
            sums[i] += sums[i-1];
        unordered_map<int, int> hash;
        hash[0] = 1;
        for (int i = 0; i != nums.size(); i++) {
            res += hash[sums[i] - k];
            hash[sums[i]]++;
        }
        return res;
    }
};
