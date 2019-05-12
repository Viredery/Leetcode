class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> jumpNum(nums.size(), 0);
        int curPos = 1;
        for (int i = 0; i != nums.size(); i++) {
            int maxLen = nums[i];
            while (curPos < nums.size() && i + maxLen >= curPos)
                jumpNum[curPos++] = jumpNum[i] + 1;    
        }
        return jumpNum.back();
    }
};
