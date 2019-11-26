class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> sequences;
        unordered_map<string, int> hash;
        for (int i = 0; i + 10 <= s.size(); i++) {
            string seq = s.substr(i, 10);
            if (++hash[seq] == 2)
                sequences.push_back(seq);
        }
        return sequences;
    }
};
