class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> dict;
        for (auto c : s) {
            dict[c]++;
        }
        for (auto c : t) {
            if (!dict.count(c) || dict[c] == 0) {
                return false;
            }
            dict[c]--;
        }
        return s.size() == t.size();
    }
};
