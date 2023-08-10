class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set<std::string> word_set{wordList.begin(), wordList.end()};
        if (!word_set.count(endWord)) {
            return 0;
        }
        // Bidirectional BFS
        std::unordered_set<std::string> begin_set;
        begin_set.insert(beginWord);
        std::unordered_set<std::string> end_set;
        end_set.insert(endWord);

        std::unordered_set<std::string> visisted = {beginWord, endWord};
        int current_length = 1;
        while (!begin_set.empty() && !end_set.empty()) {
            current_length += 1;
            std::unordered_set<std::string> next_set;
            for (const auto& word : begin_set) {
                word_set.erase(word);
                for (int i = 0; i != word.size(); ++i) {
                    for (char c = 'a'; c <= 'z'; ++c) {
                        const std::string trans_word = word.substr(0, i) + c + word.substr(i + 1);
                        if (!word_set.count(trans_word)) {
                            continue;
                        }
                        if (end_set.count(trans_word)) {
                            return current_length;
                        }
                        if (visisted.count(trans_word)) {
                            continue;
                        }
                        visisted.insert(trans_word);
                        next_set.insert(trans_word);
                    }
                }
                
            }
            begin_set = std::move(next_set);
            if (begin_set.size() > end_set.size()) {
                begin_set.swap(end_set);
            }
        }
        return 0;
    }
};

