class Solution {
public:
    string shortestPalindrome(string s) {
        int n  = s.size();
        string res(s);
        reverse(res.begin(), res.end());
        string str = s + "#" + res;
        vector<int> arr(str.size(), 0);
        for (int i = 1; i != str.size(); i++) {
            int t = arr[i - 1];
            while (t != 0 && str[t] != str[i])
                t = arr[t - 1];
            if (str[t] == str[i])
                arr[i] = t + 1;
        }
        return res.substr(0, n - arr[str.size() - 1]) + s;
    }
};