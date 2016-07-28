class Solution {
public:
    string addBinary(string a, string b) {
        int aPos = a.size() - 1, bPos = b.size() - 1;
        char aChar = '0', bChar = '0';
        string result;
        bool carry = false;
        while (aPos >= 0 || bPos >= 0) {
            aChar = aPos >= 0 ? a[aPos--] : '0';
            bChar = bPos >= 0 ? b[bPos--] : '0';
            if (false == carry) {
                if ('0' == aChar && '0' == bChar) {
                    result += "0";
                } else if ('1' == aChar && '1' == bChar) {
                    result += "0"; carry = true;
                } else
                    result += "1";
            } else {
                if ('0' == aChar && '0' == bChar) {
                    result += "1"; carry = false;
                } else if ('1' == aChar && '1' == bChar) {
                    result += "1";
                } else
                    result += "0";
            }
        }
        if (true == carry)
            result += "1";
        result.erase(result.find_last_not_of('0') + 1);
        int left = 0, right = result.size() - 1;
        while (left < right) {
            swap(result[left++], result[right--]);
        }
        if (result.empty())
            result = "0";
        return result;
    }
};