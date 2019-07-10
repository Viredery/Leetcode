class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int m1 = (n1 + n2 - 1) / 2, m2 = (n1 + n2) / 2;
        return (findNthSortedArrays(nums1, 0, nums2, 0, m1) 
                + findNthSortedArrays(nums1, 0, nums2, 0, m2)) / 2.0;
    }
    
private:
    double findNthSortedArrays(vector<int>& nums1, int start1, 
                               vector<int>& nums2, int start2,
                               int nth) {
        if (start1 == nums1.size())
            return nums2[start2 + nth];
        if (start2 == nums2.size())
            return nums1[start1 + nth];
        if (nth == 0)
            return min(nums1[start1], nums2[start2]);
        if (nth == 1) {
            if (nums1[start1] > nums2[start2])
                return findNthSortedArrays(nums1, start1, nums2, start2+1, nth-1);
            else
                return findNthSortedArrays(nums1, start1+1, nums2, start2, nth-1);
        }
        
        int max1 = INT_MAX, max2 = INT_MAX;
        int mid = nth / 2;
        if (start1 + mid < nums1.size())
            max1 = nums1[start1 + mid];
        if (start2 + mid < nums2.size())
            max2 = nums2[start2 + mid];
        if (max1 < max2)
            return findNthSortedArrays(nums1, start1+mid, nums2, start2, nth-mid);
        else
            return findNthSortedArrays(nums1, start1, nums2, start2+mid, nth-mid);
    }
};
