class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) 
            return {};
        vector<string> phone = {"", "", "abc", "def", "ghi", 
                                "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> combinations = {""};
        for (char digit : digits) {
            vector<string> newComb;
            for (char c : phone[digit - '0'])
                for (string comb : combinations)
                    newComb.push_back(comb + c);
            combinations = std::move(newComb);
        }
        return combinations;
    }
};
