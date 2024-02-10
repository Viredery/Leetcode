class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) {
            return 0;
        }
        std::vector<std::vector<int>> max_lengths(s.size(), std::vector<int>(s.size(), 0));
        
        for (int l = 0; l != s.size(); ++l) {
            max_lengths[l][l] = 1;
        }
        int global_max_length = 1;
        for (int length = 2; length <= s.size(); ++length) {
            for (int l = 0; l + length <= s.size(); ++l) {
                const int r = l + length - 1;
                if (s[l] == s[r]) {
                    max_lengths[l][r] += max_lengths[l + 1][r - 1] + 2;
                } else {
                    max_lengths[l][r] = std::max(max_lengths[l + 1][r], max_lengths[l][r - 1]);
                }
                global_max_length = std::max(global_max_length, max_lengths[l][r]);
            }
        }
        return global_max_length;
    }
};
