class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int greatest_num_pos = std::max_element(nums.begin(), nums.end()) - nums.begin();
        std::vector<int> next_greater_elements(nums.size(), -1);
        std::stack<int> st;
        for (int i = nums.size(); i > 0; --i) {
            const int pos = (i + greatest_num_pos) % nums.size();
            while (!st.empty() && st.top() <= nums[pos]) {
                st.pop();
            }
            if (!st.empty()) {
                next_greater_elements[pos] = st.top();
            }
            st.push(nums[pos]);
        }
        return next_greater_elements;
    }
};
