class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dist = 0;
        for (int i = 0; i != nums.size() && i <= dist; i++)
            dist = std::max(dist, i + nums[i]);
        return dist + 1 >= nums.size();
    }
};
