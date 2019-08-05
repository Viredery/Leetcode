class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dict;
        dict['I'] = 1; dict['V'] = 5; dict['X'] = 10; dict['L'] = 50;
        dict['C'] = 100; dict['D'] = 500; dict['M'] = 1000;
        
        vector<int> arr(s.size(), 0);
        for (int i = 0; i < s.size(); i++)
            arr[i] = dict[s[i]];
        int res = 0;
        for (int i = 0; i + 1 < s.size(); i++) {
            if (arr[i] < arr[i + 1])
                res -= arr[i];
            else
                res += arr[i];
        }
        return res + arr[s.size() - 1];
    }
};
