class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0,  nums.size() - 1);
    }
private:
    int findMin(vector<int>& nums, int left, int right) {
        if (left == right)
            return nums[left];

        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
            return findMin(nums, mid+1, right);
        if (nums[mid] < nums[right])
            return findMin(nums, left, mid);

        int min1 = findMin(nums, left, mid);
        int min2 = findMin(nums, mid+1, right);
        return min1 < min2 ? min1 : min2;
    }
};
