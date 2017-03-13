class Solution {
public:
    int totalNQueens(int n) {
        int total = 0;
        vector<int> positionVec;
        if (0 < n)
            positionVec.push_back(0);
        int pos = 0;
        while (!positionVec.empty()) {
            if (n == positionVec.size()) {
                total++;
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
        return total;
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
};