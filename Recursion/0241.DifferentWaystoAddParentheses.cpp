class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        std::vector<int> results;
        bool found_op = false;
        for (int i = 0; i != expression.size(); ++i) {
            const char c = expression[i];
            if (c >= '0' && c <= '9') {
                continue;
            }
            found_op = true;
            const std::string exp1 = expression.substr(0, i);
            const std::vector<int> res1 = exp_results.count(exp1) 
                ? exp_results[exp1] : diffWaysToCompute(exp1);
            exp_results[exp1] = res1;
            const std::string exp2 = expression.substr(i + 1);
            const std::vector<int> res2 = exp_results.count(exp2) 
                ? exp_results[exp2] : diffWaysToCompute(exp2);
            exp_results[exp2] = res2;
            for (const int& num1 : res1) {
                for (const int& num2 : res2) {
                    if (c == '+') {
                        results.push_back(num1 + num2);
                    } else if (c == '-') {
                        results.push_back(num1 - num2);
                    } else {
                        results.push_back(num1 * num2);
                    }
                }
            }
        }
        return found_op ? results : std::vector<int>{std::stoi(expression)};
    }
private:
    std::map<std::string, std::vector<int>> exp_results;
};
