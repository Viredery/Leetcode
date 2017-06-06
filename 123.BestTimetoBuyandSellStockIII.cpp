class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
             return 0;
        vector<vector<int>> maxVec(2, vector<int>(prices.size(), 0));
        int maxProf = 0;
        int tmpMax = -1 * prices[0];
        for (int i = 1; i != prices.size(); i++) {
            maxVec[0][i] = max(tmpMax + prices[i], maxVec[0][i-1]);
            tmpMax = max(tmpMax, -1 * prices[i]);
            maxProf = max(maxVec[0][i], maxProf);
        }
        tmpMax = maxVec[0][0] - prices[0];
        for (int i = 1; i != prices.size(); i++) {
            maxVec[1][i] = max(tmpMax + prices[i], maxVec[1][i-1]);
            tmpMax = max(tmpMax, maxVec[0][i] - prices[i]);
            maxProf = max(maxVec[1][i], maxProf);
        }
        return maxProf;
    }
};
