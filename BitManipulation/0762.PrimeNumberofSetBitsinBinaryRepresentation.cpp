class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int cnt = 0;
        for (int i = L; i <= R; i++)
            cnt += isPrime(bitsNum(i));
        return cnt;
    }
private:
    int bitsNum(int num) {
        int cnt = 0;
        while (num != 0) {
            cnt += num & 1;
            num >>= 1;
        }
        return cnt;
    }
    
    bool isPrime(int cnt) {
        static unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        return primes.find(cnt) != primes.end();
    }
};
