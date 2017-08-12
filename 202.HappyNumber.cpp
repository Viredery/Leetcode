class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> arr;
        while (n != 1) {
            int sum = 0;
            while (n != 0) {
                int val = n % 10;
                sum += val * val;
                n /= 10;
            }
            if (arr.find(sum) != arr.end())
                return false;
            arr.insert(sum);
            n = sum;
        }
        return true;
    }
};