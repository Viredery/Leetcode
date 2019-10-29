class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        return reversePairs(nums, l, r);
    }
private:
    int reversePairs(vector<int>& nums, int left, int right) {
        if (left >= right)
            return 0;
        int mid = left + (right - left) / 2;
        int cntLeft = reversePairs(nums, left, mid);
        int cntRight = reversePairs(nums, mid+1, right);
        
        int cnt = merge(nums, left, mid, right);
        return cntLeft + cntRight + cnt;
    }
    
    int merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> tmp1(nums.begin() + left, nums.begin() + mid + 1);
        vector<int> tmp2(nums.begin() + mid + 1, nums.begin() + right + 1);
        
        int s1 = 0, e1 = tmp1.size(), s2 = 0, e2 = tmp2.size();
        int cnt = 0;
        
        int s = left;
        while (s1 < e1 && s2 < e2) {
            if (tmp1[s1] / 2 > tmp2[s2] || (tmp1[s1] / 2 == tmp2[s2] && tmp1[s1] % 2 == 1)) {
                cnt += (e2 - s2);
                s1++;
            } else
                s2++;
        }
 
        s1 = 0, s2 = 0;
        while (s1 < e1 && s2 < e2) {
            if (tmp1[s1] > tmp2[s2])
                nums[s++] = tmp1[s1++];
            else
                nums[s++] = tmp2[s2++];
        }
        while (s1 < e1)
            nums[s++] = tmp1[s1++];
        while (s2 < e2)
            nums[s++] = tmp2[s2++];
        
        return cnt;
    }
};
