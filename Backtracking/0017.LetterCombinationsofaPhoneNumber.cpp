class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> phone;
        phone['2'] = "abc";
        phone['3'] = "def";
        phone['4'] = "ghi";
        phone['5'] = "jkl";
        phone['6'] = "mno";
        phone['7'] = "pqrs";
        phone['8'] = "tuv";
        phone['9'] = "wxyz";
        
        vector<string> combinations;
        string tracking;
        backtrack(digits, 0, phone, tracking, combinations);
        return combinations;
    }
private:
    void backtrack(string& digits, 
                   int pos,
                   map<char, string>& phone,
                   string& tracking, 
                   vector<string>& combinations) {
        if (pos == digits.size() && !tracking.empty())
            combinations.push_back(tracking);
            return;
        }
        string letters = phone[digits[pos]];
        for (char letter : letters) {
            tracking.push_back(letter);
            backtrack(digits, pos+1, phone, tracking, combinations);
            tracking.pop_back();
        }
    }
};
