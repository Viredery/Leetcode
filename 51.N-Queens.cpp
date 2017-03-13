class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if (0 >= n) return res;
        vector<int> positionVec;
        positionVec.push_back(0);
        int pos = 0;
        while (!positionVec.empty()) {
            if (n == positionVec.size()) {
                printQueens(res, positionVec);
                pos = positionVec.back() + 1;
                positionVec.pop_back();
                if (!positionVec.empty() && pos == n) {
                    pos = positionVec.back() + 1;
                    positionVec.pop_back();
                }                
            }
            while (!positionVec.empty() && !check(positionVec, pos)) {
                pos++;
                while (!positionVec.empty() && pos == n) {
                    pos = positionVec.back() + 1;
                    positionVec.pop_back();
                }
            }
            if (positionVec.empty() && pos == n)
                break;
            positionVec.push_back(pos);
            pos = 0;
        }
        return res;
    }
    bool check(vector<int> &positionVec, int x) {
        int y = positionVec.size();
        int difference = y - x, sum = y + x;
        for (int i = 0; i != y; i++) {
            if (i - positionVec[i] == difference || i + positionVec[i] == sum || positionVec[i] == x)
                return false;
        }
        return true;
    }
    void printQueens(vector<vector<string>> &res, vector<int> &positionVec) {
        vector<string> curRes;
        int n = positionVec.size();
        for (int i = 0; i != n; i++) {
            std::string str(n, '.');
            str[positionVec[i]] = 'Q';
            curRes.push_back(std::move(str));
        }
        res.push_back(std::move(curRes));
    }
};