public class Solution {
    public int removeElement(int[] nums, int val) {
        int distanceMove = 0, length = nums.length;
        for (int i = 0; i != length; i++) {
            if (nums[i] == val)
                distanceMove++;
            else
                nums[i - distanceMove] = nums[i];
        }
        return length - distanceMove;
    }
}