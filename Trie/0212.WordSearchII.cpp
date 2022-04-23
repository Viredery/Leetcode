class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie = new Node();
        for (const auto& word : words) {
            Node* cur = trie;
            for (int i = 0; i != word.size(); ++i) {
                if (!cur->next[word[i] - 'a']) {
                    cur->next[word[i] - 'a'] = new Node();
                }
                cur = cur->next[word[i] - 'a'];
            }
            cur->word = word;
        }
        
        std::vector<std::string> res;
        for (int i = 0; i != board.size(); ++i) {
            for (int j = 0; j != board[0].size(); ++j) {
                dfs(board, i, j, trie, &res);
            }
        }
        return res;
    }
private:
    const vector<int> dx = {0, 1, 0, -1};
    const vector<int> dy = {1, 0, -1, 0};
    
    struct Node {
        std::string word;
        std::vector<Node*> next;
        Node() : next(26, nullptr) {}
    };
    
    void dfs(vector<vector<char>>& board, int i, int j, Node* root, std::vector<std::string>* res) {
        if (board[i][j] == '.') {
            return;
        }
        if (!root->next[board[i][j] - 'a']) {
            return;
        }
        if (!root->next[board[i][j] - 'a']->word.empty()) {
            res->push_back(root->next[board[i][j] - 'a']->word);
            root->next[board[i][j] - 'a']->word.clear();
        }
        
        const char letter = board[i][j];
        board[i][j] = '.';
        for (int pos = 0; pos != dx.size(); pos++) {
            int x = i + dx[pos], y = j + dy[pos];
            if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
                continue;
            }
            dfs(board, x, y, root->next[letter - 'a'], res);
        }
        board[i][j] = letter;
    }
    
    Node* trie;
};
