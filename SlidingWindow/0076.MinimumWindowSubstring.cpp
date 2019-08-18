class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return "";
        map<char, int> dictT, dictS;
        for (char c : t) {
            dictT[c]++;
        }
        cout << dictT.size() << endl;
        vector<int> res{0, -1};
        int require = 0;
        int left = 0, right = -1;
        while (right < (int)s.size() -1 || require == dictT.size()) {
            if (require < dictT.size()) { // move right
                right++;
                if (dictT.find(s[right]) != dictT.end()) {
                    dictS[s[right]]++;
                    if (dictS[s[right]] == dictT[s[right]])
                        require++;
                }
            } else { // move left
                if (dictT.find(s[left]) != dictT.end()) {
                    dictS[s[left]]--;
                    if (dictS[s[left]] < dictT[s[left]])
                        require--;
                }
                left++;
            }
            if (require == dictT.size() && 
                    (res[0] > res[1] || res[1] - res[0] > right - left)) {
                res[0] = left;
                res[1] = right;
            }
        }
        return res[0] > res[1] ? "" : s.substr(res[0], res[1] - res[0] + 1); 
    }
};
