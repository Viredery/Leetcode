class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        
        nth_element(nums.begin(), nums.begin() + (nums.size() + 1) / 2 - 1, nums.end(), less<int>());
        int medium = nums[(nums.size() + 1) / 2 - 1];

        
        int n = nums.size();
        int left = 0, i = 0, right = n - 1;
        
        while (i <= right) {
            
            if (nums[newIndex(i, n)] > medium) {
                swap(nums, newIndex(i++, n), newIndex(left++, n));
            } else if (nums[newIndex(i, n)] < medium) {
                swap(nums, newIndex(i, n), newIndex(right--, n));
            } else 
                i++;
        }
    }
    
private:
    int newIndex(int index, int n) {
        return (1 + 2 * index) % (n | 1);
    }
    
    void swap(vector<int>& nums, int idx1, int idx2) {
        int tmp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = tmp;
    }
};
