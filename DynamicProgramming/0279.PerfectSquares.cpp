class Solution {
public:
    int numSquares(int n) {
        std::vector<int> arr(n + 1, INT_MAX);
        arr[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                arr[i] = std::min(arr[i], arr[i - j * j] + 1);
            }
        }
        return arr[n];
    }
};
