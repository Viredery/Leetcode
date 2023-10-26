class Solution {
public:
    int change(int amount, vector<int>& coins) {
        std::vector<int> cnts(amount + 1, 0);
        cnts[0] = 1;
        for (const auto& coin : coins) {
            for (int j = 1; j <= amount; ++j) {
                if (j - coin >= 0) {
                    cnts[j] += cnts[j - coin];
                }
            }
        }
        return cnts[amount];
    }
};
