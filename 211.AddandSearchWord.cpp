class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
     
    ~WordDictionary() {
        delete root;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for (int i = 0; i != word.size(); i++) {
            if (node->getChild(word[i]) == nullptr)
                node->addChild(word[i]);
            node = node->getChild(word[i]);
        }
        node->setFlag();
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, root);
    }
    
private:
    class TrieNode {
    public:        
        TrieNode() : childArray(26, nullptr), wordFlag(false) {}
        
        ~TrieNode() {
            for (int i = 0; i != 26; i++)
                if (childArray[i] != nullptr)
                    delete childArray[i];
        }
        
        void addChild(char c) {
            TrieNode* node = new TrieNode();
            childArray[c - 'a'] = node;
            childList.push_back(node);
        }
        
        TrieNode* getChild(char c) {
            return childArray[c - 'a'];
        }
        
        void setFlag() {
            wordFlag = true;
        }
        
        bool getFlag() {
            return wordFlag;
        }
        
        list<TrieNode*> getChildList() {
            return childList;
        }
    private:
        vector<TrieNode*> childArray;
        list<TrieNode*> childList;
        bool wordFlag;
    };
    
    TrieNode* root;
    
    bool search(string word, TrieNode* node) {
        for (int i = 0; i != word.size(); i++) {
            if (word[i] != '.') {
                node = node->getChild(word[i]);
                if (node == nullptr)
                    return false;
            } else {
                list<TrieNode*> childList = node->getChildList();
                for (auto child : childList) {
                    if (search(word.substr(i+1), child) == true)
                        return true;
                }
                return false;
            }
        }
        return node->getFlag() == true;        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */