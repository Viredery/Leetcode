public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int length1 = nums1.length, length2 = nums2.length;
        int l = (length1 + length2 + 1) / 2;
        int r = (length1 + length2 + 2) / 2;
        return (getKth(nums1, 0, nums2, 0, l) + getKth(nums1, 0, nums2, 0, r)) / 2;
    }

    private double getKth(int[] nums1, int start1, int[] nums2, int start2, int pos) {
        if (start1 > nums1.length - 1)
            return nums2[start2 + pos - 1];
        if (start2 > nums2.length - 1)
            return nums1[start1 + pos - 1];
        if (pos == 1)
            return Math.min(nums1[start1], nums2[start2]);

        int median1 = Integer.MAX_VALUE, median2 = Integer.MAX_VALUE;
        if (start1 + pos / 2 - 1 < nums1.length)
            median1 = nums1[start1 + pos / 2 - 1];
        if (start2 + pos / 2 - 1 < nums2.length)
            median2 = nums2[start2 + pos / 2 - 1];
        if (median1 < median2)
            return getKth(nums1, start1 + pos / 2, nums2, start2, pos - pos / 2);
        else
            return getKth(nums1, start1, nums2, start2 + pos / 2, pos - pos / 2);
    }
}