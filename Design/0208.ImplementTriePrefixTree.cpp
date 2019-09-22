class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            TrieNode* child = node->getNode(c);
            if (child == nullptr) {
                node->setNode(c);
                child = node->getNode(c);
            }
            node = child;
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            TrieNode* child = node->getNode(c);
            if (child == nullptr)
                return false;
            node = child;
        }
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            TrieNode* child = node->getNode(c);
            if (child == nullptr)
                return false;
            node = child;
        }
        return true;
    }
private:
    class TrieNode {
    public:
        TrieNode() : isWord(false), next(26, nullptr) {}
        ~TrieNode() {
            for (TrieNode* ptr : next)
                if (ptr != nullptr)
                    delete ptr;
        }
        void setNode(char c) {
            next[c - 'a'] = new TrieNode();
        }
        TrieNode* getNode(char c) {
            return next[c - 'a'];
        }
        bool isWord;
        vector<TrieNode*> next;
    };
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
