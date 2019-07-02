class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        bool plus_one = false;
        while (i >= 0) {
            plus_one = (digits[i] + 1) / 10;
            digits[i] = (digits[i] + 1) % 10;
            if (!plus_one)
                break;
            i--;
        }
        if (plus_one)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
