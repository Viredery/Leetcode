class Solution {
public:
    int monkeyMove(int n) {
        return (pow(n) + MOD - 2) % MOD;
    }
private:
    static constexpr long MOD =  1e9 + 7;
    int pow(int n) {    
        long base = 2;
        long remainder = 1;
        while (n) {
            if (n & 1) {
                remainder = (remainder * base) % MOD;
            }
            base = (base * base) % MOD;
            n /= 2;
        }
        return static_cast<int>(remainder);
    }
};
