class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int l, int r) {
            return std::to_string(l) + std::to_string(r) > std::to_string(r) + std::to_string(l);
        });
        std::string largest_number;
        for (const auto& num : nums) {
            largest_number += std::to_string(num);
        }
        if (largest_number.empty() || largest_number.front() == '0') {
            largest_number = "0";
        }
        return largest_number;
    }
};
