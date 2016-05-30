public class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> result = new HashSet<Integer>();
        for (int i = 0; i < nums.length; i++) {
            result.add(nums[i]);
            if (result.size() != i + 1) {
                return true;
            }
        }
        return false;
    }
}