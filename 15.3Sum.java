public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new LinkedList<List<Integer>>();
        Arrays.sort(nums);
        if (nums.length < 3)
        	return result;
        int i = 0;
        while (i <= nums.length - 3) {
        	int j = i + 1;
        	int k = nums.length - 1;
        	while (j < k) {
        		int sum = nums[i] + nums[j] + nums[k];
        		if (sum == 0) {
        			result.add(Arrays.asList(nums[i], nums[j++], nums[k--]));
        		    while (j < k && nums[j] == nums[j - 1])
        		    	j++;
        		    while (j < k && nums[k] == nums[k + 1])
        		    	k--;
        		} else if (sum < 0) {
        			j++;
        			while (j < k && nums[j] == nums[j - 1])
        		    	j++;
        		} else {
        		    k--;
        		    while (j < k && nums[k] == nums[k + 1])
        		    	k--;
        		}
        	}
        	i++;
        	while (i <= nums.length - 3 && nums[i] == nums[i - 1])
        		i++;
        }
        return result;
    }
}