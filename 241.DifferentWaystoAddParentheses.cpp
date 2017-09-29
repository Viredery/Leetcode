class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        bool sign = false;
        for (int i = 0; i != input.size(); i++) {
            if (!ispunct(input[i]))
                continue;
            sign = true;
            vector<int> left_vec = diffWaysToCompute(input.substr(0, i));
            vector<int> right_vec = diffWaysToCompute(input.substr(i+1));        
            for (auto left : left_vec)
                for (auto right : right_vec)
                    res.push_back(input[i] == '+' ? left + right : (input[i] == '-' ? left - right : left * right));
        }
        return sign ? res : vector<int>{stoi(input)};
    }
};