class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty())
            return;
        vector<int>::iterator left = nums.begin();
        vector<int>::iterator right = nums.end() - 1;
        vector<int>::iterator i = left;
        while(i <= right) {
            if(*i == 0) {
                swap(*left, *i);
                left++;
                i++;
            } else if (*i == 2) {
                swap(*right, *i);
                right--;
            } else
                i++;
        }
    }
};
