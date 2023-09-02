class Solution {
public:
    int characterReplacement(string s, int k) {
        std::vector<int> cnts(26, 0);
        int left = 0;
        int max_len = 0;
        for (int i = 0; i != s.size(); ++i) {
            ++cnts[s[i] - 'A'];
            while (i - left + 1 > GetMaxCount(cnts) + k) {
                --cnts[s[left] - 'A'];
                ++left;
            }
            max_len = std::max(max_len, i - left + 1);
        }
        return max_len;
    }
private:
    int GetMaxCount(const std::vector<int>& cnts) const {
        return *std::max_element(cnts.begin(), cnts.end());
    }
};
