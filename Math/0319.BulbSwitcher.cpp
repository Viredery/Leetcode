class Solution {
public:
    int bulbSwitch(int n) {
        int bulb = 0, num = 1;
        while (num * num <= n)
            bulb++, num++;
        return bulb;
    }
};
