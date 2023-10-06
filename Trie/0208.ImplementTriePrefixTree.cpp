class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        TrieNode* node = &root;
        for (const auto& c : word) {
            node = node->CreateNextNodeIfNeeded(c);
        }
        node->is_word = true;
    }
    
    bool search(string word) {
        TrieNode* node = &root;
        for (const auto& c : word) {
            node = node->GetNextNode(c);
            if (!node) {
                return false;
            }
        }
        return node->is_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = &root;
        for (const auto& c : prefix) {
            node = node->GetNextNode(c);
            if (!node) {
                return false;
            }
        }
        return true;
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

        TrieNode* GetNextNode(char c) {
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

    TrieNode root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
