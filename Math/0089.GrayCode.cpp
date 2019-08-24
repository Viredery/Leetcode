class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        for (int i = 1; i <= n; i++) {
            int size = res.size();
            for (int j = size-1; j >= 0; j--) {
                res.push_back(res[j] + (1 << (i-1)));
            }
        }
        return move(res);
    }
};
