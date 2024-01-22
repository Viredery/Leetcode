class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        std::vector<int> dp(arr.size(), -1);
        int num_max_jumps = 1;
        for (int i = 0; i != arr.size(); ++i) {
            if (dp[i] < 0) {
                dp[i] = maxJumps(arr, i, d, &dp);
            }
            num_max_jumps = std::max(num_max_jumps, dp[i]);
        }
        return num_max_jumps;
    }

private:
    int maxJumps(vector<int>& arr, int start, int d, std::vector<int>* dp) {
        if (dp->at(start) >= 0) {
            return (*dp)[start];
        }
        bool left_search = true;
        bool right_search = true;
        int num_jump = 1;
        for (int i = 1; i <= d; i++) {
            if (left_search && start - i >= 0 && arr[start - i] < arr[start]) {
                const int next_idx = start - i;
                num_jump = std::max(num_jump, 1 + maxJumps(arr, next_idx, d, dp));
            } else {
                left_search = false;
            }
            if (right_search && start + i < arr.size() && arr[start + i] < arr[start]) {
                const int next_idx = start + i;
                num_jump = std::max(num_jump, 1 + maxJumps(arr, next_idx, d, dp));
            } else {
                right_search = false;
            }
        }
        (*dp)[start] = num_jump;
        return num_jump;
    }
};
