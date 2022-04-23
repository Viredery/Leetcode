class WordDictionary {
public:
    WordDictionary() {
        trie = new Node();
    }
    
    void addWord(string word) {
        Node* cur = trie;
        for (int i = 0; i != word.size(); ++i) {
            if (!cur->next[word[i] - 'a']) {
                cur->next[word[i] - 'a'] = new Node();
            }
            cur = cur->next[word[i] - 'a'];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        return search(word, 0, trie);
    }
private:
    struct Node {
        bool end;
        std::vector<Node*> next;
        Node() : end(false), next(26, nullptr) {}
    };
    
    bool search(const string& word, int pos, const Node* cur) {
        for (int i = pos; i != word.size(); ++i) {
            if (word[i] == '.') {
                for (auto ptr : cur->next) {
                    if (ptr && search(word, i + 1, ptr)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (!cur->next[word[i] - 'a']) {
                    return false;
                }
                cur = cur->next[word[i] - 'a'];
            }
        }
        return cur->end;
    }
    
    Node* trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
