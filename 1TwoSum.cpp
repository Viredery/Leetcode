class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        int size = nums.size();
        for(int pos = 0; pos != size; pos++) {
            if(hash.count(nums[pos]) == 0)
                hash[target- nums[pos]] = pos;
            else {
                vector<int> result;
                result.push_back(hash[nums[pos]]);
                result.push_back(pos);
                return result;
            }
        }
    }
};
