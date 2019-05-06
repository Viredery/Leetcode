class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {searchFirstTarget(nums, target), searchLastTarget(nums, target)};
    }
private:
    int searchFirstTarget(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target && (mid == 0 || nums[mid - 1] < target))
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return -1;
    }
    
    int searchLastTarget(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target && (mid == nums.size() - 1 || nums[mid + 1] > target))
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return -1;
    }
};
