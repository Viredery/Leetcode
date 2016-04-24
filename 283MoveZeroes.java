public class Solution {
    public void moveZeroes(int[] nums) {
        int moveDistance = 0, len = nums.length;
        for (int i = 0; i != len; i++) {
            if(nums[i] == 0)
                moveDistance++;
            else
                nums[i - moveDistance] = nums[i];
        }
        for (int i = len - moveDistance; i != len; i++) {
            nums[i] = 0;
        }
    }
}