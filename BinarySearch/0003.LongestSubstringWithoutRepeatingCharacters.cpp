class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), sum = n1 + n2;
        if (sum % 2 != 0)
            return findNSortedArrays(nums1, 0, nums2, 0, sum/2);
        return (findNSortedArrays(nums1, 0, nums2, 0, sum/2) +
                findNSortedArrays(nums1, 0, nums2, 0, sum/2-1)) / 2.0;
    }
    
private:
    double findNSortedArrays(vector<int>& nums1, int s1,
                             vector<int>& nums2, int s2,
                             int target) {
        if (target == 0) {
            if (s1 < nums1.size() && s2 < nums2.size())
                return min(nums1[s1], nums2[s2]);
            else if (s1 < nums1.size())
                return nums1[s1];
            else
                return nums2[s2];
        }
        if (s1 >= nums1.size())
            return nums2[s2+target];
        if (s2 >= nums2.size())
            return nums1[s1+target];
        int m1 = INT_MAX, m2 = INT_MAX;
        if (s1 + (target-1) / 2 < nums1.size())
            m1 = nums1[s1 + (target-1) / 2];
        if (s2 + (target-1) / 2 < nums2.size())
            m2 = nums2[s2 + (target-1) / 2];

        if (m1 < m2)
            return findNSortedArrays(nums1, s1+(target-1)/2+1, 
                                     nums2, s2, 
                                     target-(target-1)/2-1);
        else
            return findNSortedArrays(nums1, s1, 
                                     nums2, s2+(target-1)/2+1, 
                                     target-(target-1)/2-1);        
};
