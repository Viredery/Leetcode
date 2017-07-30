class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        
        if (k >= prices.size() / 2) {
		    int maxPro = 0;
		    for (int i = 1; i < prices.size(); i++)
			    if (prices[i] > prices[i-1])
				    maxPro += prices[i] - prices[i-1];
		    return maxPro;
	    }
        
        vector<vector<int>> maxPro(k+1, vector<int>(prices.size(), 0));
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j != prices.size(); j++) {
                for (int k = 0; k < j; k++)
                    maxPro[i][j] = max(maxPro[i][j], maxPro[i-1][k] + prices[j] - prices[k]);
                maxPro[i][j] = max(maxPro[i][j], maxPro[i][j-1]);
            }
        }
        return maxPro[k][prices.size()-1];
    }
};