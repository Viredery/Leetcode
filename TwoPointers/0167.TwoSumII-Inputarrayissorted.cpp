class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() < 2) {
            return {};
        }
        int left = 0;
        int right = numbers.size() - 1;
        while (left <= right) {
            const int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};
            }
            if (sum > target) {
                --right;
            } else {
                ++left;
            }
        }
        return {};
    }
};
