class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int num_open = 0;
        int num_close = 0;
        for (const auto& c : s) {
            if (c == '(') {
                ++num_open;
            } else if (c == ')') {
                if (--num_open < 0) {x
                    num_open = 0;
                    ++num_close;
                }
            }
        }
        std::vector<std::string> parentheses;
        std::string generator = "";
        backtracking(s, 0, num_open, num_close, 0, 'c', &generator, &parentheses);
        return parentheses;
    }

private:
    void backtracking(const std::string& s,
                      int start,
                      int num_open,
                      int num_close,
                      int open, 
                      char last_character,
                      std::string* generator,
                      std::vector<std::string>* parentheses) {
        if (start == s.size()) {
            if (num_open == 0 && num_close == 0) {
                parentheses->push_back(*generator);
            }
            return;
        }
        const char c = s[start];
        if (c == '(') {
            generator->push_back(c);
            backtracking(s, start + 1, num_open, num_close, open + 1, '(', generator, parentheses);
            generator->pop_back();
            if (num_open > 0 && last_character != '(') {
                backtracking(s, start + 1, num_open - 1, num_close, open, 'c', generator, parentheses);
            }
        } else if (c == ')') {
            if (open > 0) {
                generator->push_back(c);
                backtracking(s, start + 1, num_open, num_close, open - 1, ')', generator, parentheses);
                generator->pop_back();
            }
            if (num_close > 0 && last_character != ')') {
                backtracking(s, start + 1, num_open, num_close - 1, open, 'c', generator, parentheses);
            }
        } else {
            generator->push_back(c);
            backtracking(s, start + 1, num_open, num_close, open, 'c', generator, parentheses);
            generator->pop_back();
        }
    }
};
