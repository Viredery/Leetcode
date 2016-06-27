public class Solution {
    public int maxArea(int[] height) {
        if(2 > height.length)
            return 0;
        int left = 0, right = height.length - 1;
        int maxArea = 0;
        while (left < right) {
            int pointSmaller = Math.min(height[left], height[right]);
            if (maxArea < pointSmaller * (right - left))
                maxArea = pointSmaller * (right - left);
            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        return maxArea;
    }
}