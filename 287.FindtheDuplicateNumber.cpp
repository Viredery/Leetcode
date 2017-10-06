class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int no_large_num = 0, large_num = 0;
            for (int i = 0; i != nums.size(); i++) {
                if (nums[i] > right || nums[i] < left)
                    continue;
                if (nums[i] <= mid)
                    no_large_num++;
                else
                    large_num++;
            }
            if (mid - left + 1 < no_large_num)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};