class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (const auto& word : words) {
            TrieNode* node = &root_;
            for (const auto& c : word) {
                node = node->CreateNextNodeIfNeeded(c);
            }
            node->word = word;
        }
        
        std::vector<std::string> found_words;

        for (int i = 0; i != board.size(); ++i) {
            for (int j = 0; j != board[i].size(); ++j) {
                std::vector<std::vector<bool>> visited(board.size(), 
                                                       std::vector<bool>(board[i].size(), false));
                findWords(board, i, j, "", &root_, &visited, &found_words);
            }
        }
        return found_words;
    }

private:
    struct TrieNode {
        TrieNode() : next(26, nullptr) {}
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

        std::string word;
        std::vector<TrieNode*> next;
    };

    static constexpr std::array<std::pair<int, int>, 4> DIRECTIONS = {
        std::make_pair(-1, 0), std::make_pair(0, -1), std::make_pair(1, 0), std::make_pair(0, 1)};

    void findWords(vector<vector<char>>& board,
                   int x, 
                   int y,
                   const std::string& word,
                   TrieNode* node,
                   std::vector<std::vector<bool>>* visited, 
                   std::vector<std::string>* found_words) {
        if (!node->word.empty()) {
            found_words->push_back(node->word);
            node->word.clear();
        }
        if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size()) {
            return;
        }
        if ((*visited)[x][y]) {
            return;
        }
        const char c = board[x][y];
        if (!node->GetNextNode(c)) {
            return;
        }
        (*visited)[x][y] = true;
        for (const auto& [dx, dy] : DIRECTIONS) {
            const int i = x + dx;
            const int j = y + dy;
            findWords(board, i, j, word + c, node->GetNextNode(c), visited, found_words);
        }
        (*visited)[x][y] = false;
    }

    TrieNode root_;
};
