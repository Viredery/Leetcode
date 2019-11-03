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
            if (target <= nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left < nums.size() && nums[left] == target ? left : -1;
    }
    
    int searchLastTarget(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right >= 0 && nums[right] == target ? right : -1;
    }
};
