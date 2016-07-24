class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	if (nums.size() < 2)
    		return;
        for (int i = nums.size() - 2; i >= 0; i--) {
        	for (int j = nums.size() - 1; j > i; j--) {
        		if (nums[j] > nums[i]) {
        			swap(nums[i], nums[j]);
        			vector<int>::iterator iter = nums.begin();
        			for (int pos = 0; pos <= i; pos++)
        				iter++;
        			sort(iter, nums.end());
        			return;
        		}
        	}
        }
        reverse(nums.begin(), nums.end());
    }
};