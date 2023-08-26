class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> dict;
        std::stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            dict[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        std::vector<int> next_greater_elements;
        next_greater_elements.reserve(nums1.size());
        for (const auto& num : nums1) {
            next_greater_elements.push_back(dict[num]);
        }
        return next_greater_elements;
    }
};
