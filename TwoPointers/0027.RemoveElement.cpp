class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0, count = 0;
        while (cur < nums.size()) {
            if (nums[cur] == val)
                count++;
            else
                nums[cur-count] = nums[cur];
            cur++;
        }
        return nums.size() - count;
    }
};
