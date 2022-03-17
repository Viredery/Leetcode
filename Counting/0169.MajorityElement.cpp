class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int selected_num = nums.front();
        int count = 1;
        for (int i = 1; i != nums.size(); ++i) {
            if (nums[i] == selected_num) {
                ++count;
            } else if (--count < 0) {
                selected_num = nums[i];
                count = 1;
            }
        }
        return selected_num;
    }
};
