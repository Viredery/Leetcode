class Solution {
public:
    int jump(vector<int>& nums) {
        int max_reachable_position = 0;
        int current_end = 0;
        int num_jump = 0;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            max_reachable_position = std::max(max_reachable_position, i + nums[i]);
            if (i == current_end) {
                current_end = max_reachable_position;
                ++num_jump;
            }
        }
        return num_jump;
    }
};
