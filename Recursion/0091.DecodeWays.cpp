class Solution {
public:
    int numDecodings(string s) {
        std::vector<int> counts(s.size(), 0);
        return Search(s, 0, &counts);
    }
private:
    int Search(const std::string& s, int pos, std::vector<int>* counts) {
        if (pos == s.size()) {
            return 1;
        }
        if (counts->at(pos) > 0) {
            return counts->at(pos);
        }
        if (s[pos] == '0') {
            return 0;
        }
        if (pos + 1 < s.size() && (s[pos] == '1' || (s[pos] == '2' && s[pos + 1] <= '6'))) {
            counts->at(pos) = Search(s, pos + 2, counts) + Search(s, pos + 1, counts);
        } else {
            counts->at(pos) = Search(s, pos + 1, counts);
        }
        return counts->at(pos);
    }
};
