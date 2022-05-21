class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> products(nums.size(), 1);
        for (int i = 1; i != nums.size(); ++i) {
            products[i] = products[i - 1] * nums[i - 1];
        }
        for (int i = static_cast<int>(nums.size()) - 2; i >= 0; --i) { 
            products[i] *= nums[i + 1];
            nums[i] *= nums[i + 1];
        }
        return products;
    }
};
