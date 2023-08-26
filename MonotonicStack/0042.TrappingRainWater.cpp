class Solution {
public:
    int trap(vector<int>& height) {
        std::stack<int> st;
        int trap_size = 0;
        for (int i = 0; i != height.size(); ++i) {
            while (!st.empty() && height[st.top()] <= height[i]) {
                int idx = st.top();
                st.pop();
                if (st.empty()) {
                    continue;
                }
                const int relative_height = std::min(height[i], height[st.top()]) - height[idx];
                const int width = i - st.top() - 1;
                trap_size += relative_height * width;
            }
            st.push(i);
        }
        return trap_size;
    }
};
