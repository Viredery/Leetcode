class Solution {
public:
    int longestSubstring(string s, int k) {
        std::unordered_set<char> unique_characters;
        for (const auto& c : s) {
            unique_characters.insert(c);
        }
        int max_len = 0;
        for (int valid_cnt = 1; valid_cnt <= unique_characters.size(); ++valid_cnt) {
            std::unordered_map<char, int> occurrences;
            int left = 0;
            for (int i = 0; i != s.size(); ++i) {
                occurrences[s[i]]++;
                while (occurrences.size() > valid_cnt) {
                    if (--occurrences[s[left]] == 0) {
                        occurrences.erase(s[left]);
                    }
                    left++;
                }
                bool all_at_least_k = true;
                for (const auto& [_, cnt] : occurrences) {
                    if (cnt < k) {
                        all_at_least_k = false;
                    }
                }
                if (all_at_least_k) {
                    max_len = std::max(i - left + 1, max_len);
                }
            }
        }
        return max_len;
    }
};
