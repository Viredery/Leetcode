class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10)
            return {};
        vector<string> res;
        int state(0), pos(0);
        unordered_map<int, int> state_map;
        while (pos < 9) // calculate the state of nine-letter-long sequence in this loop
            state = state << 3 | s[pos++] & 0x7;
        while (pos < s.size()) // the state of the first ten-letter-long sequence will be stored in the map
            if (state_map[state = (state << 3 & 0x3fffffff) | (s[pos++] & 0x7)]++ == 1)
                res.push_back(s.substr(pos-10, 10));
        return res;
    }
};