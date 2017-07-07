class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        vector<int> diff(size, 0);
        for (int i = 0; i != size; i++)
            diff[i] = gas[i] - cost[i];
        int start = 0, end = 0, sum = 0;
        for (int i = 0; i != size * 2 && start < size; i++) {
            sum += diff[i % size];
            if (sum < 0) {
                sum = 0;
                end = start = i + 1;
            } else if (++end - start == size)
                return start;
        }
        return -1;
    }
};