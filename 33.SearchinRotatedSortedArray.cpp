class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] > nums[end]) {
                if (target > nums[mid] || target <= nums[end])
                    start = mid + 1;
                else
                    end = mid;
            } else {
                if (target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid;
            }
        }
        if (start == end && nums[start] == target) return start;
        else return -1;
        
    }
};