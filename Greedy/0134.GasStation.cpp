class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start_idx = -1;
        int sum = 0;
        for (int i = 0; i != gas.size() * 2; ++i) {
            const int idx = i % gas.size();
            sum += gas[idx] - cost[idx];
            if (sum < 0) {
                start_idx = -1;
                sum = 0;
            } else if (start_idx == -1) {
                start_idx = i;
            }
        }
        return start_idx >= 0 && start_idx < gas.size() ? start_idx : -1;
    }
};
