class Solution {
public:
    string minWindow(string s, string t) {
        int start_pos = 0;
        int min_size = s.size() + 1;
        std::unordered_map<char, int> cnts;
        for (const auto& c : t) {
            cnts[c]++;
        }
        int num_occurrence = 0;
        int left = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (cnts.count(s[i]) && --cnts[s[i]] >= 0) {
                num_occurrence += 1;
            }
            while (num_occurrence == t.size()) {
                if (min_size > i - left + 1) {
                    start_pos = left;
                    min_size = i - left + 1;
                }
                if (cnts.count(s[left]) && ++cnts[s[left]] > 0) {
                    num_occurrence -= 1;
                }
                left++;
            }
        }
        return min_size > s.size() ? "" : s.substr(start_pos, min_size);
    }
};
