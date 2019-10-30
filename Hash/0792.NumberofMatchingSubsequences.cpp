class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<const char*> mapped[128];
        for (auto& word : words)
            mapped[word[0]].push_back(word.c_str());
        for (char c : S) {
            if (mapped[c].empty())
                continue;
            auto wordVec = mapped[c];
            mapped[c].clear();
            for (auto ptr : wordVec)
                mapped[*(ptr+1)].push_back(ptr+1);
        }
        return mapped[0].size();
    }
};
