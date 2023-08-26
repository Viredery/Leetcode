class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<int> st;
        int max_area = 0;
        for (int i = 0; i != heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                const int pre_height = heights[st.top()];
                st.pop();
                const int width = i - (st.empty() ? 0 : st.top() + 1);
                max_area = std::max(max_area, width * pre_height);
            }
            st.push(i);
        }
        while (!st.empty()) {
            const int pre_height = heights[st.top()];
            st.pop();
            const int width = heights.size() - (st.empty() ? 0 : st.top() + 1);
            max_area = std::max(max_area, width * pre_height);
        }
        return max_area;
    }
};
