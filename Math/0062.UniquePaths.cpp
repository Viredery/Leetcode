class Solution {
public:
    int uniquePaths(int m, int n) {
        // combinatories
        double res = 1;
        int a = m + n - 2;
        int b = min(m, n) - 1;
        for (int i = 0; i != b; i++)
            res = res * (a-i) / (b-i);
        return round(res);
    }
};
