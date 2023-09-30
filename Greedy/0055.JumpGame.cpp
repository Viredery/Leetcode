class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_arrivable = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if (i > max_arrivable) {
                break;
            }
            max_arrivable = std::max(max_arrivable, i + nums[i]);
        }
        return max_arrivable >= nums.size() - 1;
    }
};
