public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
    	List<List<Integer>> result = new LinkedList<List<Integer>>();
    	if (nums.length < 4)
    		return result;

    	Arrays.sort(nums);

    	int firstPos = 0;
    	while (firstPos < nums.length - 3) {
    		threeSum(nums, target, result, firstPos);
    		firstPos++;
    		while (firstPos < nums.length - 3 && nums[firstPos] == nums[firstPos - 1])
    			firstPos++;
    	}
    	return result;
    }

    private void threeSum(int[] nums, int target, List<List<Integer>> result, int firstPos) {
    	int secondPos = firstPos + 1;
    	while (secondPos < nums.length - 2) {
    		int twoNumSum = nums[firstPos] + nums[secondPos];
    		int leftPos = secondPos + 1, rightPos = nums.length - 1;
    		while (leftPos < rightPos) {
    			int sum = twoNumSum + nums[leftPos] + nums[rightPos];
    			if (sum == target) {
    				result.add(Arrays.asList(nums[firstPos], nums[secondPos], nums[leftPos], nums[rightPos]));
    				leftPos++;
    				while (leftPos < rightPos && nums[leftPos] == nums[leftPos - 1])
    					leftPos++;
    				rightPos--;
    				while (leftPos < rightPos && nums[rightPos] == nums[rightPos + 1])
    					rightPos--;
    			} else if (sum < target) {
    				leftPos++;
    				while (leftPos < rightPos && nums[leftPos] == nums[leftPos - 1])
    					leftPos++;
    			} else {
    				rightPos--;
    				while (leftPos < rightPos && nums[rightPos] == nums[rightPos + 1])
    					rightPos--;
    			}
    		}
    		secondPos++;
    		while (secondPos < nums.length - 2 && nums[secondPos] == nums[secondPos - 1])
    			secondPos++;
    	}
    }
}