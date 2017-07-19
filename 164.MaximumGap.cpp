class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int maxNum = *max_element(nums.begin(), nums.end());
        int radix = 10, exp = 1;
        // assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range
        vector<int> aux(nums.size());
        while (maxNum / exp > 0) {
            vector<int> count(radix, 0);
            for (int i = 0; i != nums.size(); i++)
                count[(nums[i] / exp) % radix]++;
            for (int i = 1; i != count.size(); i++)
                count[i] += count[i - 1];
            for (int i = nums.size() - 1; i >= 0; i--)
                aux[--count[(nums[i] / exp) % radix]] = nums[i];
            copy(aux.begin(), aux.end(), nums.begin());
            exp *= 10;
        }
        int maxGap = 0;
        for (int i = 1; i != nums.size(); i++)
            maxGap = max(maxGap, nums[i] - nums[i-1]);
        return maxGap;
    }
};