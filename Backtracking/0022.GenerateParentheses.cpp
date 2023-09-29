class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> parentheses;
        std::string parenthesis;
        recurse(0, 0, n, &parenthesis, &parentheses);
        return parentheses;
    }
private:
    void recurse(int left, int right, int n, std::string* parenthesis, std::vector<std::string>* parentheses) {
        if (right == n) {
            parentheses->push_back(*parenthesis);
            return;
        }
        if (left < n) {
            parenthesis->push_back('(');
            recurse(left + 1, right, n, parenthesis, parentheses);
            parenthesis->pop_back();
        }
        if (right < left) {
            parenthesis->push_back(')');
            recurse(left, right + 1, n, parenthesis, parentheses);
            parenthesis->pop_back();
        }
    }
};
