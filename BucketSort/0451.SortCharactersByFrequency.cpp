class Solution {
public:
    string frequencySort(string s) {
        std::unordered_map<char, int> cnts;
        int max_cnt = 0;
        for (const auto& c : s) {
            max_cnt = std::max(max_cnt, ++cnts[c]);
        }
        std::vector<std::vector<char>> buckets(max_cnt + 1);
        for (const auto& [character, cnt] : cnts) {
            buckets[cnt].push_back(character);
        }
        std::vector<char> res(s.size());
        int cur_pos = 0;
        for (int cnt = max_cnt; cnt >= 1; --cnt) {
            for (const auto& c : buckets[cnt]) {
                for (int i = 0; i != cnt; ++i) {
                    res[cur_pos++] = c;
                }
            }
        }
        return std::string(res.begin(), res.end());
    }
};
