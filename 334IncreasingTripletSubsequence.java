public class Solution {
    public boolean increasingTriplet(int[] nums) {
        int[] twoNumArray = new int[2];
        int twoNumArrayLength = 0;
        int[] oneNumArray = new int[1];
        int oneNumArrayLength = 0;
        for (int num : nums) {
        	if (oneNumArrayLength == 0) {
        		oneNumArray[0] = num;
        		oneNumArrayLength++;
        		continue;
        	} else if (num <= oneNumArray[0]) {
        		oneNumArray[0] = num;
        	} else if (twoNumArrayLength == 0) {
        		twoNumArrayLength = 2;
        		twoNumArray[0] = oneNumArray[0];
        		twoNumArray[1] = num;
        	} else if (twoNumArray[1] < num) {
        	    return true;
        	} else {
        		twoNumArray[0] = oneNumArray[0];
        		twoNumArray[1] = num;
        	}
        }
        return false;
    }
}