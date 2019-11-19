class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        // find minimum
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l >> 1);
            if (nums[mid] <= nums.back())
                r = mid;
            else
                l = mid + 1;
        }
        // l == r == minimum in rotated sorted array
        if (target <= nums.back()) {
            r = nums.size() - 1;
        } else {
            l = 0, r--;
        }
        // search in sorted array
        while (l < r) {
            int mid = l + (r - l >> 1);
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return nums[l] == target ? l : -1;
    }
};
