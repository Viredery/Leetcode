class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        int sum = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i] == false)
                continue;
            sum++;
            for (int j = i*2; j < n; j += i)
                isPrime[j] = false;
        }
        return sum;
    }
};