class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() < 2)
            return ratings.size();
        int rise = 0, fall = 0, candies = 0, oldSlope = 0;
        for (int i = 1; i != ratings.size(); i++) {
            int newSlope = ratings[i] > ratings[i-1] ? 1 : (ratings[i] < ratings[i-1] ? -1 : 0);
            if ((oldSlope > 0 && newSlope == 0) || (oldSlope < 0 && newSlope >= 0)) {
                candies += count(rise) + count(fall) + max(rise, fall); 
                rise = fall = 0;
            }
            if (newSlope > 0)
                rise++;
            else if (newSlope < 0)
                fall++;
            else
                candies++;
            oldSlope = newSlope;
        }
        return candies + count(rise) + count(fall) + max(rise, fall) + 1;
    }
private:
    int count(int n) {
        return n * (n + 1) / 2;
    }
};