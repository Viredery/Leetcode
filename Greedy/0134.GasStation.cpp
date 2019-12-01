class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0, j; i < n; i += j+1) {
            int total = 0;
            for (j = 0; j < n; j++) {
                total += gas[(i+j) % n] - cost[(i+j) % n];
                if (total < 0)
                    break;
            }
            if (j == n)
                return i;
        }
        return -1;
    }
};
