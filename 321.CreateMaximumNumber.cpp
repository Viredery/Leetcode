class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> res(k, 0);
        for (int i = max(0, k - n2); i <= k && i <= n1; i++) {
            vector<int> candidate = merge(findKMax(nums1, i), findKMax(nums2, k - i), k);
            if (greater(candidate, 0, res, 0))
                res = move(candidate);
        }
        return res;
    }
private:
    vector<int> merge(vector<int> nums1, vector<int> nums2, int k) {
        vector<int> res(k, 0);
        for (int s1 = 0, s2 = 0, i = 0; i != k; i++) 
            res[i] = greater(nums1, s1, nums2, s2) ? nums1[s1++] : nums2[s2++];
        return move(res);
    }
    
    bool greater(vector<int> nums1, int start1, 
                 vector<int> nums2, int start2) {
        while (start1 < nums1.size() && start2 < nums2.size() &&
               nums1[start1] == nums2[start2]) {
            start1++;
            start2++;
        }
        return start2 == nums2.size() || (start1 < nums1.size() && nums1[start1] > nums2[start2]);
    }
    
    vector<int> findKMax(vector<int>& nums, int k) {
        vector<int> res(k, 0);
        for (int j = 0, i = 0; i != nums.size(); i++) {
            while (nums.size()-i-k+j > 0 && j > 0 && res[j-1] < nums[i])
                j--;
            if (j < k)
                res[j++] = nums[i];
        }
        return move(res);
    }
};
