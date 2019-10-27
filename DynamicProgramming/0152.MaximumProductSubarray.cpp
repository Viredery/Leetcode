class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int res = nums[0];
        for (int i = 1; i != nums.size(); i++) {
            int prod1 = maxProd * nums[i];
            int prod2 = minProd * nums[i];
            
            maxProd = max(nums[i], max(prod1, prod2));
            minProd = min(nums[i], min(prod1, prod2));
            
            res = max(res, maxProd);
        }
        return res;
    }
};
