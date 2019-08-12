class Solution {
public:
    int totalNQueens(int n) {
        vector<int> status;
        return dp(n, status);
    }
private:
    int dp(const int n, vector<int>& status) {
        if (status.size() == n) {
            return 1;
        }
        int sum = 0;
        for (int i = 0; i != n; i++) {
            if (!check(status, n, i))
                continue;
            status.push_back(i);
            sum += dp(n, status);
            status.pop_back();
        }
        return sum;
    }
    bool check(vector<int>& status, int n, int pos) {
        for (int i = 0; i < status.size(); i++)
            if (status[i] == pos)
                return false;
        for (int i = 1; pos - i >= 0 && status.size() >= i; i++)
            if (status[status.size()-i] == pos - i)
                 return false;
        for (int i = 1; pos + i < n && status.size() >= i; i++)
            if (status[status.size()-i] == pos + i)
                 return false;
        return true;
    }
};
