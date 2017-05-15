class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() > 12) return res;
        for (int i = 0; i < 3 && i+3 < s.size(); i++) {
            string one = s.substr(0, i+1);
            if (stoi(one) > 255 || (i > 0 && s[0] == '0')) break;
            for (int j = i+1; j < i+4 && j+2 < s.size(); j++) {
                string two = s.substr(i+1, j-i);
                if (stoi(two) > 255 || (j > i+1 && s[i+1] == '0')) break;
                for (int k = j+1; k < j+4 && k+1 < s.size(); k++) {
                    string three = s.substr(j+1, k-j);
                    if (stoi(three) > 255 || (k > j+1 && s[j+1] == '0')) break;
                    string four = s.substr(k+1);
                    if (stoi(four) > 255 || (s.size() > k+2 && s[k+1] == '0')) continue;
                    res.push_back(one + "." + two + "." + three + "." + four);
                }
            }
        }
        return res;
    }
};