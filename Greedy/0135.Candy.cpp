class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty())
            return 0;
        int maxPos = 0, maxVal = 1;
        int candies = 1, curCandies = 1;
        for (int i = 1; i != ratings.size(); i++) {
            if (ratings[i] >= ratings[i - 1]) {
                curCandies = ratings[i] == ratings[i - 1] ? 1 : curCandies + 1;
                candies += curCandies;
                maxPos = i, maxVal = curCandies;
            } else {
                if (curCandies == 1) {
                    candies += i - maxPos - 1;
                    if (maxVal == i - maxPos)
                        maxVal += 1, candies += 1;
                }
                curCandies = 1;
                candies += curCandies;
            }
        }
        return candies;
    }
};
