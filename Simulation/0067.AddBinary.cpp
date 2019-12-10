class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size(), n2 = b.size(), n = max(n1, n2);
        
        string res(n, '0');
        int carry = 0;
        for (int i = 0; i != n; i++) {
            char c1 = n1 - i >= 1 ? a[n1-1-i] : '0'; 
            char c2 = n2 - i >= 1 ? b[n2-1-i] : '0';
            int val = carry + (c1 - '0') + (c2 - '0');
            carry = val / 2;
            res[n-1-i] = '0' + val % 2;
        }
        return carry ? '1' + res : res;
    }
};
