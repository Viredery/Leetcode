class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0, left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                maxLeft = std::max(maxLeft, height[left]);
                total += maxLeft - height[left];
                left++;
            } else {
                maxRight = std::max(maxRight, height[right]);
                total += maxRight - height[right];
                right--;
            }
        }
        return total;
    }
};
