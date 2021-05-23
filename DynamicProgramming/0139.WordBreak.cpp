class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<int> segmented(s.size() + 1, 0);
        segmented[0] = 1;
        for (int i = 0; i != s.size(); ++i) {
            for (const auto& word : wordDict) {
                if (i + 1 >= word.size() &&
                    segmented[i + 1 - word.size()] == 1 &&
                    word == s.substr(i + 1 - word.size(), word.size())) {
                    segmented[i + 1] = 1;
                    break;
                }
            }
        }
        return segmented[s.size()];
    }
};
