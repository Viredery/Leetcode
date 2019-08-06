class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parentheses;
        string tracking;
        generateParenthesis(n, n, tracking, parentheses);
        return parentheses;
    }
private:
    void generateParenthesis(int left, int right, 
                             string& tracking, 
                             vector<string>& parentheses) {
        if (right == 0) {
            parentheses.push_back(tracking);
            return;
        }
        
        if (left > 0) {
            tracking += '(';
            generateParenthesis(left-1, right, tracking, parentheses);
            tracking.pop_back();
        }
        if (right > left) {
            tracking += ')';
            generateParenthesis(left, right-1, tracking, parentheses);
            tracking.pop_back();
        }
    }
};
