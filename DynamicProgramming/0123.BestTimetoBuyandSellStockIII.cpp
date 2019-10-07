class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int holdFirst = INT_MIN, profFirst = 0;
        int holdSecond = INT_MIN, profTotal = 0;
        for (int price : prices) {
            profTotal  = max(profTotal,  price + holdSecond);
            holdSecond = max(holdSecond, profFirst - price);
            profFirst  = max(profFirst,  price + holdFirst);
            holdFirst  = max(holdFirst,  -price);
        }
        return profTotal;
    }
};
