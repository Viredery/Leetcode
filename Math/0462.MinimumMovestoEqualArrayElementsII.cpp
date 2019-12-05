class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        std::nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int moves = 0, mid = nums[n / 2];
        for (auto num : nums)
            moves += std::abs(num - mid);
        return moves;
    }
};
