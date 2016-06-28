public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        if (nums.length < 3)
            return Integer.MAX_VALUE;
        int min = nums[0] + nums[1] + nums[2];
        int i = 0;
        while (i <= nums.length - 3) {
        	int j = i + 1;
        	int k = nums.length - 1;
        	while (j < k) {
        		int sum = nums[i] + nums[j] + nums[k];
        		if (sum == target) {
        		    return target;
        		} else if (sum < target) {
        		    if (Math.abs(min - target) > Math.abs(sum - target))
        		        min = sum;
        			j++;
        			while (j < k && nums[j] == nums[j - 1])
        		    	j++;
        		} else {
        		    if (Math.abs(min - target) > Math.abs(sum - target))
        		        min = sum;
        		    k--;
        		    while (j < k && nums[k] == nums[k + 1])
        		    	k--;
        		}
        	}
        	i++;
        	while (i <= nums.length - 3 && nums[i] == nums[i - 1])
        		i++;
        }
        return min;
    }
}