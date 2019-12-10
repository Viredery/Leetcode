class Solution {
public:
    bool isUgly(int num) {
        vector<int> factors = {2, 3, 5};
        for (int factor : factors)
            while (num > 0 && num % factor == 0)
                num /= factor;
        return num == 1;
    }
};
