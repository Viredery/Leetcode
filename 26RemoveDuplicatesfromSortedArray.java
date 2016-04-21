public class Solution {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        if (len == 0 || len == 1)
            return len;
        int prevNum = nums[0];
        int moveDistance = 0;
        for (int pos = 1; pos != len; pos++) {
            if (prevNum == nums[pos]) {
                moveDistance++;
            } else {
                prevNum = nums[pos - moveDistance] = nums[pos];
            }
        }
        return len - moveDistance;
    }
}
