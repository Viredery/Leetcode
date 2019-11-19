class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {searchFirstTarget(nums, target), searchLastTarget(nums, target)};
    }
private:
    int searchFirstTarget(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l >> 1);
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return l < nums.size() && nums[l] == target ? l : -1;
    }
    
    int searchLastTarget(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l + 1 >> 1);
            if (nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        return l < nums.size() && nums[l] == target ? l : -1;
    }
};
