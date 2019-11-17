class Solution {
public:
    bool makesquare(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(),
                  [](int& l, int& r) { return l > r; });
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == 0 || sum % 4 != 0)
            return false;

        vector<int> sides(4, 0);
        return dfs(nums, 0, sides, sum / 4);
    }
private:
    bool dfs(vector<int>& nums, int pos, vector<int>& sides, const int maxLength) {
        if (pos == nums.size()) {
            for (int i = 0; i != 4; i++)
                if (sides[i] != maxLength)
                    return false;
            return true;
        }
        for (int i = 0; i != 4; i++) {
            if (sides[i] + nums[pos] > maxLength)
                continue;
            sides[i] += nums[pos];
            if (dfs(nums, pos+1, sides, maxLength))
                return true;
            sides[i] -= nums[pos];
        }
        return false;
    }
};
