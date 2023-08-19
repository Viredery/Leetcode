class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int start = 0;
        int end = nums1.size();
        while (start <= end) {
            const int mid1 = start + (end - start) / 2;
            const int mid2 = (nums1.size() + nums2.size() + 1) / 2 - mid1;

            const int left1 = mid1 == 0 ? std::numeric_limits<int>::min() : nums1[mid1 - 1];
            const int right1 = mid1 == nums1.size() ? std::numeric_limits<int>::max() : nums1[mid1];
            const int left2 = mid2 == 0 ? std::numeric_limits<int>::min() : nums2[mid2 - 1];
            const int right2 = mid2 == nums2.size() ? std::numeric_limits<int>::max() : nums2[mid2];

            if (left1 <= right2 && left2 <= right1) {
                if ((nums1.size() + nums2.size()) % 2 != 0) {
                    return std::max(left1, left2);
                }
                return (std::max(left1, left2) + std::min(right1, right2)) / 2.0;
            }
            if (left1 > right2) {
                end = mid1 - 1;
            } else {
                start = mid1 + 1;
            }
        }
        // The program should never get here.
        return -1;
    }
};
