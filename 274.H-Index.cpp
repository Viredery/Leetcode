class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        vector<int> nums(citations.size() + 1, 0);
        for (int citation : citations) {
            if (citation > citations.size())
                nums[citations.size()]++;
            else
                nums[citation]++;
        }
        int t = 0;
        for (int i = citations.size(); i >= 0; i--) {
            t += nums[i];
            if (t >= i)
                return i;
        }
        return 0;
    }
};