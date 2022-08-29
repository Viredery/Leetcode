class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::map<char, std::string> matched;
        std::set<std::string> observed;
        int start_pos = 0;
        for (const auto& c : pattern) {
            if (start_pos == s.size()) {
                return false;
            }
            const int end_pos = s.find_first_of(' ', start_pos);
            std::string word;
            if (end_pos == std::string::npos) {
                word = s.substr(start_pos);
                start_pos = s.size();
            } else {
                word = s.substr(start_pos, end_pos - start_pos);
                start_pos = end_pos + 1;
            }
            if (!matched.count(c) && observed.count(word)) {
                return false;
            }
            if (matched.count(c) && matched[c] != word) {
                return false;
            }
            matched[c] = word;
            observed.insert(word);
        }
        return start_pos == s.size();
    }
};
