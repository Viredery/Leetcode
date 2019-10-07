class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxProf = 0;
        for (int i = 0; i != prices.size(); i++) {
            minPrice = minPrice > prices[i] ? prices[i] : minPrice;
            maxProf = maxProf > prices[i] - minPrice ? maxProf : prices[i] - minPrice;
        }
        return maxProf;
    }
};
