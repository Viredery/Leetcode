class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stored_nums;
        for (const auto& token : tokens) {
            if (token.size() != 1 || !kValidOperators.count(token[0])) {
                stored_nums.push(std::stoi(token));
                continue;
            }
            const int second_num = stored_nums.top();
            stored_nums.pop();
            const int first_num = stored_nums.top();
            stored_nums.pop();
            stored_nums.push(CalculateByOperator(token[0], first_num, second_num));
        }
        return stored_nums.top();
    }
private:
    const std::unordered_set<char> kValidOperators{'+', '-', '*', '/'};
    
    int CalculateByOperator(char ops, int first_num, int second_num) const {
        switch (ops) {
            case '+':
                return first_num + second_num;
            case '-':
                return first_num - second_num;
            case '*':
                return first_num * second_num;
            case '/':
                return first_num / second_num;
            default:
                return 0;
        }
    }
};
