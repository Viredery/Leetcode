class Solution {
public:
    string getPermutation(int n, int k) {
        string permutation;
        vector<char> nums;
        int length = 1;
        for (int i = 1; i <= n; i++) {
            nums.push_back('0' + i);
            length *= i;
        }
        
        k = k - 1;
        while (k > 0) {
            length = length / nums.size();
            int idx = k / length;
            k = k % length;
            char c = nums[idx];
            permutation += c;
            nums.erase(nums.begin() + idx);
            
        }
        for (int i = 0; i != nums.size(); i++)
            permutation += nums[i];
        return permutation;
    }
};
