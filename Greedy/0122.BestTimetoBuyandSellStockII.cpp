class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int holdPrice = INT_MAX, maxProf = 0;
        for (int i = 0; i != prices.size(); i++) {
            holdPrice = holdPrice > prices[i] ? prices[i] : holdPrice;
            if (prices[i] - holdPrice > 0) {
                maxProf += prices[i] - holdPrice;
                holdPrice = prices[i];
            }
        }
        return maxProf;
    }
};
