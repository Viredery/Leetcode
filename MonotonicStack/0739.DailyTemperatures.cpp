class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> wait_days(temperatures.size(), 0);
        std::stack<int> st;
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if (!st.empty()) {
                wait_days[i] = st.top() - i;
            }
            st.push(i);
        }
        return wait_days;
    }
};
