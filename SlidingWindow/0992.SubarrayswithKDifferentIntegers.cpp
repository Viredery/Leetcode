class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k - 1);
    }
private:
    long subarraysWithAtMostKDistinct(vector<int>& nums, int k) {
        std::unordered_map<int, int> cnts;
        long num = 0;
        int left = 0;
        for (int i = 0; i != nums.size(); ++i) {
            cnts[nums[i]]++;
            while (cnts.size() > k) {
                if (--cnts[nums[left]] == 0) {
                    cnts.erase(nums[left]);
                }
                left++;
            }
            num += i - left + 1;
        }
        return num;
    }
};
