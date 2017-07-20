class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        string res = ((numerator > 0) ^ (denominator > 0)) ? "-" : "";
        long lNumerator = abs(static_cast<long>(numerator));
        long lDenominator = abs(static_cast<long>(denominator));
        if (lNumerator > lDenominator) {
            res += to_string(lNumerator / lDenominator);
            lNumerator %= lDenominator;
        }
        if (lNumerator == 0)
            return res;
        if (res.size() == 0 || (res.size() == 1 && res[0] == '-'))
            res += '0';
        res += '.';
        unordered_map<int, int> remainder;
        int length = res.size();
        int pos = 0;
        remainder[lNumerator] = pos++;
        while (lNumerator != 0) {
            int val = lNumerator * 10 / lDenominator;
            lNumerator = (lNumerator * 10) % lDenominator;
            res += '0' + val;
            if (remainder.find(lNumerator) != remainder.end()) {
                res.insert(length + remainder[lNumerator], 1, '(');
                res += ')';
                break;
            }
            remainder[lNumerator] = pos++;
        }
        return res;
    }
};