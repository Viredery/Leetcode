class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) {
            return 0;
        }
        std::vector<bool> is_primes(n, true);
        is_primes[0] = false;
        is_primes[1] = false;
        for (int i = 2; i * i < n; ++i) {
            if (!is_primes[i]) {
                continue;
            }
            for (int j = i * i; j < n; j += i) {
                is_primes[j] = false;
            }
        }
        int cnt = 0;
        for (int i = 0; i < is_primes.size(); ++i) {
            if (is_primes[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};
