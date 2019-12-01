class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for (int pos = 0; pos != num.size(); pos++) {
            while (!res.empty() && res.back() > num[pos] && k) {
                res.pop_back();
                k--;
            }
            res += num[pos];
        }
        while (k--) 
            res.pop_back();
        
        int i = 0;
        while (i < res.size() && res[i] == '0')
            i++;
        if (i == res.size())
            return "0";
        return res.substr(i);
    }
};
