class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int total = 0;
        shared_ptr<int> buyPricePtr = nullptr;
        for (int i = 0; i != prices.size() - 1; i++)
            if (nullptr == buyPricePtr) {
                if (prices[i] < prices[i+1])
                    buyPricePtr = make_shared<int>(prices[i]);
            } else if (prices[i] > prices[i+1]) {
                total += prices[i] - *buyPricePtr;
                buyPricePtr = nullptr;
            }
        if (nullptr != buyPricePtr)
            total += prices[prices.size() - 1] - *buyPricePtr;
        return total;
    }
};