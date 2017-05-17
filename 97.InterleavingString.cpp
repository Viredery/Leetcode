class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 + n2 != s3.size()) return false;
        bool *arr = new bool[(n1+1)*(n2+1)];
        arr[0] = true;
        for (int i = 1; i != n1 + 1; i++)
            arr[i*(n2+1)] = arr[(i-1)*(n2+1)] && s1[i-1] == s3[i-1];
        for (int i = 1; i != n2 + 1; i++)
            arr[i] = arr[i-1] && s2[i-1] == s3[i-1];
        for (int i = 1; i != n1 + 1; i++)
            for (int j = 1; j != n2 + 1; j++) {
                arr[i*(n2+1) + j] = (arr[(i-1)*(n2+1) + j] && s1[i-1] == s3[i+j-1]) || 
                                    (arr[i*(n2+1) + j-1] && s2[j-1] == s3[i+j-1]);
            }
        return arr[(n1+1)*(n2+1)-1];
    }
};
