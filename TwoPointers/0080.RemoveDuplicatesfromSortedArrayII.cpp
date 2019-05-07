class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre = -1, cur = 0, next = 0;
        bool repeated = false;
        while (cur < nums.size()) {
            if (++next < nums.size() && nums[next] == nums[cur]) {
                repeated = true;
                while (++next < nums.size() && nums[next] == nums[cur]) ;
            }  
            int val = nums[cur];
            nums[++pre] = val;
            if (repeated) {
                nums[++pre] = val;
                repeated = false;
            }
            cur = next;
        }
        return pre + 1;
    }
};
