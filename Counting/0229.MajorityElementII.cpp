class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int major1 = 0, major2 = 0, cnt1 = 0, cnt2 = 0;
        for (const auto& num : nums) {
            if (num == major1) {
                cnt1++;
            } else if (num == major2) {
                cnt2++;
            } else if (cnt1 == 0) {
                major1 = num;
                cnt1++;
            } else if (cnt2 == 0) {
                major2 = num;
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (const auto& num : nums) {
            if (num == major1) {
                cnt1++;
            } else if (num == major2) {
                cnt2++;
            }
        }
        std::vector<int> res;
        if (cnt1 > nums.size() / 3) {
            res.push_back(major1);
        }
        if (cnt2 > nums.size() / 3) {
            res.push_back(major2);
        }
        return res;
    }
};
