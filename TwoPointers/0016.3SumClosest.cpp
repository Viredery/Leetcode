class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int dis = INT_MAX, res = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i + 2 < nums.size(); i++)
            twoSum(nums, i, target, dis, res);
        return res;
    }
private:
    void twoSum(vector<int>& nums, int pos, int target, int& dis, int& res) {
        int left = pos + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right] + nums[pos];
            int curDis = sum <= target ? target - sum : sum - target;
            if (curDis < dis) {
                dis = curDis;
                res = sum;
            }
            if (sum <= target)
                left++;
            else
                right--;
        }
    }
};
