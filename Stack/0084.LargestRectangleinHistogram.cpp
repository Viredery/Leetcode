class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<int> s;
        int n = heights.size(), maxArea = 0;
        for (int i = 0; i != n; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int idx = s.top();
                s.pop();
                maxArea = std::max(
                    maxArea, heights[idx] * (s.empty() ? i : i - s.top() - 1)
                );
            }
            s.push(i);
        }
        while (!s.empty()) {
            int idx = s.top();
            s.pop();
            maxArea = std::max(
                maxArea, heights[idx] * (s.empty() ? n : n - s.top() - 1)
            );
        }
        return maxArea;
    }
};
