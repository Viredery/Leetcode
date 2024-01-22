class Solution {
public:
    bool canJump(vector<int>& nums) {
        int current_fastest_position = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if (i > current_fastest_position) {
                break;
            }
            current_fastest_position = std::max(current_fastest_position, i + nums[i]);
        }
        return current_fastest_position + 1 >= nums.size();
    }
};
