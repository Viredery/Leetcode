class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty())
            return {};
        unordered_map<string, int> counts;
        for (auto word : words)
            counts[word]++;
        vector<int> positions;
        int len = s.size(), wordLen = words[0].size(), num = words.size();
        for (int i = 0; i < len - wordLen * num + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            while (j < num) {
                string word = s.substr(i + j * wordLen, wordLen);
                if (counts.find(word) == counts.end())
                    break;
                seen[word]++;
                if (seen[word] > counts[word])
                    break;
                j++;
            }
            if (j == num)
                positions.push_back(i);
        }
        return positions;
    }
};
