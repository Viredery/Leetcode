class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int n = s1.size();
        if (n == 0) return true;
        bool *arr = new bool[n*n*n];
        for (int i = 0; i != n; i++)
            for (int j = 0; j != n; j++)
                arr[0*n*n + i*n + j] = s1[i] == s2[j] ? true : false;

        for (int l = 1; l != n; l++) {
            for (int i = 0; i != n-l; i++) {
                for (int j = 0; j != n-l; j++) {
                    bool res = false;
                    for (int k = 0; k != l; k++) {
                        res = res || (arr[k*n*n + i*n + j] && arr[(l-k-1)*n*n + (i+k+1)*n + (j+k+1)]);
                        res = res || (arr[k*n*n + i*n + (j+l-k)] && arr[(l-k-1)*n*n + (i+k+1)*n + j]);
                    }
                    arr[l*n*n + i*n + j] = res;
                }
            }
        }
        bool scrambleString = arr[(n-1)*n*n + 0*n + 0];
        delete[] arr;
        return scrambleString;
    }
};
