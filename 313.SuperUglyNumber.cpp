class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> index(primes.size(), 0), uglyNumber(n, INT_MAX);
        uglyNumber[0] = 1;
        for (int i = 1; i != n; i++) {
            for (int j = 0; j != primes.size(); j++)
                uglyNumber[i] = min(uglyNumber[i], uglyNumber[index[j]] * primes[j]);
            for (int j = 0; j != primes.size(); j++)
                index[j] += uglyNumber[i] == uglyNumber[index[j]] * primes[j];
        }
        return uglyNumber[n - 1];
    }
};