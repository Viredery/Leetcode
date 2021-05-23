class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> sentences;
        vector<int> tracked;
        if (s.empty()) {
            return sentences;
        }
        tracked.push_back(0);
        wordBreak(s, 0, wordDict, &tracked, &sentences);
        return sentences;
    }
private:
    void wordBreak(const string& s, 
                   int start, 
                   const vector<string>& wordDict, 
                   vector<int>* tracked,
                   vector<string>* sentences) {
        if (start == s.size()) {
            std::string sentence;
            for (int i = 0; i + 1 < tracked->size(); ++i) {
                sentence += s.substr((*tracked)[i], (*tracked)[i+1] - (*tracked)[i]);
                if (i + 2 != tracked->size()) {
                    sentence += " ";
                }
            }
            sentences->push_back(sentence);
        }
        for (const auto& word : wordDict) {
            if (start + word.size() <= s.size() && s.substr(start, word.size()) == word) {
                tracked->push_back(start + word.size());
                wordBreak(s, start + word.size(), wordDict, tracked, sentences);
                tracked->pop_back();
            }
        }
        
    }
};

