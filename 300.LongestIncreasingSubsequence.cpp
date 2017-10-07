class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> arr(nums.size(), 0);
        arr[0] = nums[0];
        int length = 1;
        for (int i = 1; i != nums.size(); i++) {
            if (nums[i] <= arr[0]) {
                arr[0] = nums[i];
                continue;
            }
            int j = 1;
            while (j < length) {
                if (arr[j-1] < nums[i] && arr[j] >= nums[i]) {
                    arr[j] = nums[i];
                    break;
                }
                j++;
            }
            if (j == length) {
                length++;
                arr[j] = nums[i];
            }
        }
        return length;
    }
};