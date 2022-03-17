class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        int base = 0;
        for (int i = columnTitle.size() - 1; i >= 0; i--) {
            base = (base == 0) ? 1 : base * 26;
            result += static_cast<int>(columnTitle[i] - '@') * base;
        }
        return result;
    }
};
