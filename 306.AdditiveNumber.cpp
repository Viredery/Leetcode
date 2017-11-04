class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.empty())
            return false;
        for (int i = 1; i < num.size()-1; i++) {
            if (num[0] == '0' && i != 1)
                break;
            for (int j = i+1; j < num.size(); j++) {
                unsigned long firstNum = stoul(num.substr(0, i)), secondNum = stoul(num.substr(i, j-i));
                if (num[i] == '0' && j - i != 1)
                    break;
                int minLen = max(i, j - i);
                if (helpr(num, j, minLen, firstNum, secondNum))
                    return true;
                if (helpr(num, j, minLen+1, firstNum, secondNum))
                    return true;
            }
        }
        return false;
    }
private:
    bool helpr(string num, int pos, int len, unsigned long firstNum, unsigned long secondNum) {
        if (pos + len > num.size())
            return false;
        if (num[pos] == '0' && len != 1)
            return false;
        unsigned long thirdNum = stoul(num.substr(pos, len));
        if (firstNum + secondNum != thirdNum)
            return false;
        if (pos + len == num.size() || helpr(num, pos+len, len, secondNum, thirdNum)
                || helpr(num, pos+len, len+1, secondNum, thirdNum))
            return true;
        return false;
    }
};