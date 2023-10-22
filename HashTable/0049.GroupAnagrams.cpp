class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> groups;
        std::unordered_map<std::string, std::vector<std::string>> dict;
        for (const auto& str : strs) {
            dict[sort(str)].push_back(str);
        }
        for (auto& [_, group] : dict) {
            groups.push_back(std::move(group));
        }
        return groups;
        
    }
private:
    std::string sort(const std::string& str) {
        constexpr int kLetterSize = 26;
        static std::array<int, kLetterSize> counts;
        counts.fill(0);
        for (const auto& c : str) {
            counts[c - 'a']++;
        }
        std::string sorted;
        sorted.reserve(str.size());
        for (int i = 0; i != kLetterSize; ++i) {
            while (counts[i]-- > 0) {
                sorted.push_back('a' + i);
            }
        }
        return sorted;
    }
};
