class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < int(haystack.size()) - int(needle.size()) + 1; i++) {
            int j = 0;
            while (j < needle.size()) {
                if (haystack[i + j] != needle[j])
                    break;
                j++;
            }
            if (j == needle.size())
                return i;
        }
        return -1;
    }
};


/*

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        vector<int> kmp = createKMP(needle);
        int i = 0, j = 0;
        while (i < haystack.size()) {
            while (j >= 0 && haystack[i] != needle[j])
                j = kmp[j];
            i++;
            j++;
            if (j == needle.size())
                return i-j;
        }
        return -1;
    }
private:
    vector<int> createKMP(const string& needle) {
        int n = needle.size();
        vector<int> kmp(n, 0);
        kmp[0] = -1;
        int i = 0, j = -1;
        while (i < n - 1) {
            while (j >= 0 && needle[i] != needle[j])
                j = kmp[j];
            i++;
            j++;
            kmp[i] = needle[i] != needle[j] ? j : kmp[j];
        }
        return move(kmp);
    }
};


*/
