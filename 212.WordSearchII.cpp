class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Solution::TrieNode* root = buildGraph(words);
        vector<string> res;
        for (int i = 0; i != board.size(); i++)
            for (int j = 0; j != board[0].size(); j++) {
                dfs(board, i, j, root, res);
            }
        return res;
    }
private:
    class TrieNode {
    public:
        vector<TrieNode*> childs;
        string word;
        TrieNode() : childs(26, nullptr) {}
    };
    
    TrieNode* buildGraph(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string word : words) {
            TrieNode* p = root;
            for (int i = 0; i != word.size(); i++) {
                int c = word[i] - 'a';
                if (p->childs[c] == nullptr)
                    p->childs[c] = new TrieNode();
                p = p->childs[c];
            }
            p->word = word;
        }
        return root;
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& res) {
        char c = board[i][j];
        if (c == '#' || p->childs[c-'a'] == nullptr)
            return;
        p = p->childs[c-'a'];
        if (p->word != "") {
            res.push_back(p->word);
            p->word = "";
        }
        board[i][j] = '#';
        if (i > 0) dfs(board, i-1, j, p, res);
        if (j > 0) dfs(board, i, j-1, p, res);
        if (i < board.size()-1) dfs(board, i+1, j, p, res);
        if (j < board[0].size()-1) dfs(board, i, j+1, p, res);
        board[i][j] = c;
    }
};