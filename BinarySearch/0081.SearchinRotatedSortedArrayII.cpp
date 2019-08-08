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
        if (nums[mid] == nums[left] && nums[mid] != target)
            return search(nums, left+1, mid-1, target)
                    || search(nums, mid+1, right, target);
        if (nums[mid] == target)
            return true;
        
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && nums[mid] > target)
                return search(nums, left, mid-1, target);
            return search(nums, mid+1, right, target);
        } else {
            if (nums[mid] < target && nums[right] >= target)
                return search(nums, mid+1, right, target);
            return search(nums, left, mid-1, target);
        }
    }
};
