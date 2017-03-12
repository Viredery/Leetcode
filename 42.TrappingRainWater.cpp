class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        int curCalc = INT_MAX;
        std::stack<int> s;
        for (int i = 0; i != height.size(); i++) {
            int curHeight = height[i];
            if (curHeight < curCalc)
                curCalc = curHeight;
            while (!s.empty() && height[s.top()] <= curHeight) {
                total += (height[s.top()] - curCalc) * (i - s.top() - 1);
                curCalc = height[s.top()];
                s.pop();
            }
            if (!s.empty() && curCalc != curHeight) {
                total += (curHeight - curCalc) * (i - s.top() - 1);
                curCalc = curHeight;
            }
            s.push(i);
        }
        return total;
    }
};