class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        if (*min_element(coins.begin(),coins.end()) > amount)
            return -1;
        vector<int> fewestNum(amount+1, 0);
        for (auto coin : coins) {
            if (coin <= amount)
                fewestNum[coin] = 1;
        }
        for (int i = 1; i <= amount; i++) {
            int currentNum = 0;
            if (fewestNum[i] != 0)
                continue;
            for (int j = 0; j != coins.size(); j++) {
                if (i - coins[j] > 0 && fewestNum[i - coins[j]] > 0) {
                    int tmp = fewestNum[i - coins[j]] + 1;
                    if (currentNum == 0 || tmp < currentNum)
                        currentNum = tmp;
                }
            }
            fewestNum[i] = currentNum;
        }
        return fewestNum[amount] == 0 ? -1 : fewestNum[amount];
    }
};