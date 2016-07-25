class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int left = 1, right = nums.size() - 1;
        int median = -1;
        while (left <= right) {
            int m = (left + right) / 2;
            if (nums[m] < nums[0] && nums[m] < nums[m - 1]) {
                median = m;
                break;
            } else if (nums[m] < nums[0] && nums[m] > nums[m - 1])
                right = m - 1;
            else
                left = m + 1;
        }
        int searchLeft = 0, searchRight = nums.size() - 1;
        if (target == nums[0])
            return 0;
        if (median > -1 && target > nums[0])
            searchRight = median - 1;
        if (median > -1 && target < nums[0])
            searchLeft = median;
        while (searchLeft <= searchRight) {
            int searchMedian = (searchLeft + searchRight) / 2;
            if (nums[searchMedian] == target)
                return searchMedian;
            else if (nums[searchMedian] < target)
                searchLeft = searchMedian + 1;
            else
                searchRight = searchMedian - 1;
        }
        return -1;
    }
};