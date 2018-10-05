class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unsigned seed = rand();
        std::shuffle(nums.begin(), nums.end(), std::default_random_engine(seed));
        
        return helpr(nums, 0, nums.size() - 1, k-1);
    }

private:
    int helpr(vector<int>& nums, int start, int end, int k) {

        int num = nums[start], l = start, r = end;
        int i = start+1;
        while (r - l > 0) {
            if (num < nums[i]) {
                nums[l] = nums[i];
                l++;
                i++;
            } else {
                int tmp = nums[r];
                nums[r] = nums[i];
                nums[i] = tmp;
                r--;
            }
        }
        nums[l] = num;

        
        if (l == k) 
            return nums[l];
        if (l < k)
            return helpr(nums, l+1, end, k);
        
        return helpr(nums, start, l-1, k);
    }
    

};