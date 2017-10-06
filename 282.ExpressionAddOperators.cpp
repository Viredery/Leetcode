class Solution {
public:
    vector<string> addOperators(string num, int target) {
        res.clear();
        if (num.empty()) return res;
        this->num = num;
        this->target = target;
        helper("", 0, 0, 0);
        return res;
    }
private:
    void helper(string path, int pos, long value, long multi) {
        if (pos == num.size() && target == value)
            res.push_back(path);
        for (int i = pos; i != num.size(); i++) {
            if (pos != i && num[pos] == '0')
                break;
            long cur = stol(num.substr(pos, i-pos+1));
            if (pos == 0)
                helper(num.substr(pos, i-pos+1), i+1, cur, cur);
            else {
                helper(path + "+" + num.substr(pos, i-pos+1), i+1, value + cur, cur);
                helper(path + "-" + num.substr(pos, i-pos+1), i+1, value - cur, -cur);
                helper(path + "*" + num.substr(pos, i-pos+1), i+1, value - multi + multi * cur, multi * cur);
            }
        }
    }
    vector<string> res;
    string num;
    int target;
};