class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n - 1, pos1 = m - 1, pos2 = n - 1;
        while (i > pos1) {
            if (pos1 < 0)
                nums1[i--] = nums2[pos2--];
            else if (nums1[pos1] <= nums2[pos2])
                nums1[i--] = nums2[pos2--];
            else
                nums1[i--] = nums1[pos1--];
        }
    }
};
