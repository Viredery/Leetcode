class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int max_num = *std::max_element(nums.begin(), nums.end());
        const int radix = 10;
        int exp = 1;
        while (max_num / exp) {
            std::vector<int> cnt(radix, 0);
            for (const int& num : nums) {
                cnt[num / exp % radix]++;
            }
            for (int i = 1; i != cnt.size(); ++i) {
                cnt[i] += cnt[i-1];
            }
            std::vector<int> sorted_nums(nums.size());
            for (int i = nums.size() - 1; i >= 0; --i) {
                sorted_nums[--cnt[nums[i] / exp % radix]] = nums[i];
            }
            std::copy(sorted_nums.begin(), sorted_nums.end(), nums.begin());
            exp *= radix;
        }
        int max_gap = 0;
        for (int i = 1; i < nums.size(); ++i) {
            max_gap = std::max(max_gap, nums[i] - nums[i - 1]);
        }
        return max_gap;
    }
};
