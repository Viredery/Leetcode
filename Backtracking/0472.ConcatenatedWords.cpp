class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        std::vector<std::string> satisfied_words;
        ConstructTrie(words);
        for (const auto& word : words) {
            std::vector<bool> visited(word.size() + 1, false);
            if (SearchWord(word, 0, 0, &visited)) {
                satisfied_words.push_back(word);
            }
        }
        return satisfied_words;
    }
private:
    bool SearchWord(const std::string& word,
                    int pos, 
                    int num_shorter_words,
                    std::vector<bool>* visited) {
        if (pos == word.size() && num_shorter_words > 1) {
            return true;
        }
        if (pos == word.size() || visited->at(pos)) {
            return false;
        }
        TrieNode* node = &root;
        std::vector<int> next_positions;
        for (int i = pos; i != word.size(); ++i) {
            if (!node->children[word[i] - 'a']) {
                break;
            }
            node = node->children[word[i] - 'a'];
            if (node->is_word) {
                next_positions.push_back(i + 1);
            }
        }
        for (int i = static_cast<int>(next_positions.size()) - 1; i >=0; --i) {
            if (SearchWord(word, next_positions[i], num_shorter_words + 1, visited)) {
                return true;
            }
            visited->at(next_positions[i]) = true;
        }
        return false;
    }

    void ConstructTrie(const vector<string>& words) {
        for (const auto& word : words) {
            TrieNode* node = &root;
            for (const auto& c : word) {
                if (!node->children[c - 'a']) {
                    node->children[c - 'a'] = new TrieNode{};
                }
                node = node->children[c - 'a'];
            }
            node->is_word = true;
        }
    }

    struct TrieNode {
        TrieNode() : children(26, nullptr) {}
        ~TrieNode() {
            for (const auto* child : children) {
                if (child) {
                    delete child;
                }
            }
        }

        bool is_word = false;
        std::vector<TrieNode*> children;
    };

    TrieNode root;
};
