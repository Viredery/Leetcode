class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        vector<int> kmp = createKMP(needle);
        for (int i = 0, j = 0; i != haystack.size(); i++) {
            while (j && haystack[i] != needle[j])
                j = kmp[j - 1];
            if (haystack[i] == needle[j])
                j++;
            if (j == needle.size())
                return i - j + 1;
        }
        return -1;
    }
private:
    vector<int> createKMP(const string& needle) {
        int n = needle.size();
        vector<int> kmp(n, 0);
        for (int i = 1, j = 0; i != n; i++) {
            while (j && needle[i] != needle[j])
                j = kmp[j - 1];
            if (needle[i] == needle[j])
                j++;
            kmp[i] = j;
        }
        return std::move(kmp);
    }
};
