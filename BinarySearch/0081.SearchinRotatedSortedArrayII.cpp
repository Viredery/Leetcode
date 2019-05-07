class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }
private:
    bool search(vector<int>& nums, int left, int right, int target) {
        if (left > right)
            return false;
        
        int mid = left + (right - left) / 2;
        if (nums[mid] == target || nums[right] == target)
            return true;
        if (nums[mid] == nums[right] && nums[mid] != target)
            return search(nums, left, mid-1, target)
                    || search(nums, mid+1, right-1, target);
        
        if (nums[mid] <= nums[right]) {
            if (nums[mid] < target && nums[right] > target)
                return search(nums, mid+1, right, target);
            return search(nums, left, mid-1, target);
        } else {
            if (nums[mid] < target || nums[right] > target)
                return search(nums, mid+1, right, target);
            return search(nums, left, mid-1, target);
        }
    }
};
