class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        vector<int> intRep;
        for (int i = 0; i != words.size(); i++) {
            int num = 0;
            for (char c : words[i]) {
                num |= 1 << (c - 'a');
            }
            intRep.push_back(num);
            
            for (int j = 0; j != i; j++) {
                if ((num & intRep[j]) == 0 && words[i].size() * words[j].size() > res) {
                    res = words[i].size() * words[j].size();
                }
            }
        }
        return res;
    }
};