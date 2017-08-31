class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.empty())
            return;
        TrieNode *node = root;
        for (int i = 0; i != word.size(); i++) {
            if (node->getTrieNode(word[i]) == nullptr)
                node->setTrieNode(word[i]);
            node = node->getTrieNode(word[i]);
        }
        node->setExist();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;
        for (int i = 0; i != word.size(); i++) {
            node = node->getTrieNode(word[i]);
            if (node == nullptr)
                return false;
        }
        return node->getExist();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (int i = 0; i != prefix.size(); i++) {
            node = node->getTrieNode(prefix[i]);
            if (node == nullptr)
                return false;
        }
        return true;
    }
private:
    class TrieNode {
    public:
        TrieNode() : child(26, nullptr) {
            exist = false;
        }
        ~TrieNode() {
            for (TrieNode *p : child)
                if (p != nullptr)
                    delete p;
        }
        void setTrieNode(char c) {
            child[c - 'a'] = new TrieNode();
        }
        TrieNode* getTrieNode(char c) {
            return child[c - 'a'];
        }
        void setExist() {
            exist = true;
        }
        bool getExist() {
            return exist;
        }
    private:
        vector<TrieNode *> child;
        bool exist;
    };
    
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */