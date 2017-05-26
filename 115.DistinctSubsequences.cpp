class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size() - t.size() + 1;
        if (n <= 0) return 0;
        int *arr = new int[(t.size() + 1) * n];
        for (int i = 0; i != n; i++)
            arr[i] = 1;
        for (int i = 1; i != t.size()+1; i++) {
            for (int j = 0; j != n; j++) {
                arr[i*n+j] = t[i-1] == s[i-1+j] ?
                        arr[(i-1)*n+j] + (j == 0 ? 0 : arr[i*n+j-1]) :
                        (j == 0 ? 0 : arr[i*n+j-1]);
            }
        }
        int res = arr[(t.size()+1)*n-1];
        delete[] arr;
        return res;
    }
};
