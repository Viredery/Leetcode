class WordDictionary {
public:
    WordDictionary() {}
    
    void addWord(string word) {
        TrieNode* node = &root_;
        for (const auto& c : word) {
            node = node->CreateNextNodeIfNeeded(c);
        }
        node->is_word = true;
    }
    
    bool search(string word) {
        cout << word <<endl;
        return Search(word, 0, root_);
    }

private:
    struct TrieNode {
        TrieNode() : is_word(false), next(26, nullptr) {}
        ~TrieNode() {
            for (const auto* ptr : next) {
                if (ptr) {
                    delete ptr;
                }
            }
        }

        TrieNode* GetNextNode(char c) const {
            return next[c - 'a'];
        }

        TrieNode* CreateNextNodeIfNeeded(char c) {
            if (!next[c - 'a']) {
                next[c - 'a'] = new TrieNode{};
            }
            return next[c - 'a'];
        }

        bool is_word = false;
        std::vector<TrieNode*> next;
    };

    bool Search(const string& word, int start_pos, const TrieNode& node) const {
        if (start_pos == word.size()) {
            return node.is_word;
        }
        const char c = word[start_pos];
        if (c != '.') {
            const TrieNode* next = node.GetNextNode(c);
            if (!next) {
                return false;
            }
            return Search(word, start_pos + 1, *next);
        }

        for (const auto* next_node : node.next) {
            if (next_node && Search(word, start_pos + 1, *next_node)) {
                return true;
            }
        }
        return false;
    }

    TrieNode root_;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
