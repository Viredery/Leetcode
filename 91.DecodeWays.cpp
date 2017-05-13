class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0')
            return 0;
        int num = 1, preNum = 1;
        for (int i = 1; i != s.size(); i++) {
            if (std::stoi(s.substr(i-1, 2)) <= 26) {
                if (s[i] != '0') {
                    int tmp = num;
                    num = preNum + num;
                    preNum = tmp;
                } else {
                    num = preNum;
                    preNum = 0;
                }
            } else {
                if (s[i] != '0') {
                    preNum = num;
                } else
                    return 0;
            }
        }
        return num;
    }
};
