class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        const int num_sum = std::accumulate(nums.begin(), nums.end(), 0);
        const int max_num = *std::max_element(nums.begin(), nums.end());
        return MinLargestSum(nums, k, max_num, num_sum);
    }
private:
    int MinLargestSum(const vector<int>& nums, int k, int left, int right) {
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (!IsValid(nums, k, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    bool IsValid(const vector<int>& nums, int k, int max_sum) {
        int start = 0; 
        int num_subarray = 0;
        int sum = 0;
        while (start < nums.size()) {
            sum += nums[start++];
            if (start < nums.size() && sum + nums[start] > max_sum) {
                ++num_subarray;
                sum = 0;
            }
            if (start == nums.size() && sum != 0) {
                ++num_subarray;
            }
        }
        return num_subarray <= k;
    }
};
