class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> palindrome;
        std::vector<std::string> state;
        Backtracking(s, 0, &state, &palindrome);
        return palindrome;
    }
private:
    void Backtracking(const std::string& s, 
                      int start, 
                      std::vector<std::string>* state, 
                      std::vector<std::vector<std::string>>* palindrome) {
        if (start == s.size()) {
            palindrome->push_back(*state);
            return;
        }
        for (int i = start; i != s.size(); ++i) {
            if (IsPalindrome(s, start, i)) {
                state->push_back(s.substr(start, i - start + 1));
                Backtracking(s, i + 1, state, palindrome);
                state->pop_back();
            }
        }
    }
    bool IsPalindrome(const std::string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};
