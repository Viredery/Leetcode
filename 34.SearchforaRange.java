public class Solution {
    
    int leftPosWhenEnd;
    int rightPosWhenEnd;
    
    public int[] searchRange(int[] nums, int target) {
    	int[] result = new int[2];
        leftPosWhenEnd = 0;
        rightPosWhenEnd = nums.length - 1;
        int startPos = searchStartTarget(nums, 0, nums.length - 1, target);
        result[0] = startPos;
        if (startPos == -1) {
        	result[1] = startPos;
        	return result;
        }
        leftPosWhenEnd = leftPosWhenEnd < startPos ? startPos : leftPosWhenEnd;
        int endPos = searchEndTarget(nums, leftPosWhenEnd, rightPosWhenEnd, target);
        result[1] = endPos;
        return result;
    }

    private int searchStartTarget(int[] nums, int left, int right, int target) {
    	if (left > right)
    		return -1;
    	else if (left == right)
    		return nums[left] == target ? left : -1;
    	else {
    		int middle = (left + right) / 2;
    		if (nums[middle] < target)
    			return searchStartTarget(nums, middle + 1, right, target);
    		else {
    		    if (nums[middle] > target)
    		        rightPosWhenEnd = middle;
    		    else if (middle > leftPosWhenEnd)
    		        leftPosWhenEnd = middle;
    			return searchStartTarget(nums, left, middle, target);
    		}
    	}
    }

    private int searchEndTarget(int[] nums, int left, int right, int target) {
    	if (right - left <= 1)
    		return nums[right] == target ? right : left;
        int middle = (left + right) / 2;
        if (nums[middle] == target)
            return searchEndTarget(nums, middle, right, target);
        else
        	return searchEndTarget(nums, left, middle - 1, target);
    }
}