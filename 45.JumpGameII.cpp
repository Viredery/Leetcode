class Solution {
public:
    int jump(vector<int>& nums) {
        std::vector<int> jumps(nums.size(), 0);
        int curPos = 1;
        for (int i = 0; i != nums.size(); i++) {
        	int distance = nums[i];
            while(curPos != nums.size() && i + distance >= curPos)
            	jumps[curPos++] = jumps[i] + 1;
            if (curPos == nums.size())
            	return jumps.back();
        }
        return 0;
    }
};