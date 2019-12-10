class Solution {
public:
    string convertToBase7(int num) {
        bool sign = false;
        if (num < 0) {
            sign = true;
            num = -num;
        }
        if (num == 0)
            return "0";
        
        string res;
        while (num) {
            res += '0' + num % 7;
            num /= 7;
        }
        std::reverse(res.begin(), res.end());
        return sign ? "-" + res : res;
    }
};
