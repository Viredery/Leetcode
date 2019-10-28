class Solution {
public:
    Solution(vector<int>& w) : range(w.size() + 1, 0) {
        if (w.empty())
            return;
        for (int i = 1; i <= w.size(); i++)
            range[i] = range[i-1] + w[i-1];
    }
    
    int pickIndex() {
        int maxVal = range.back();
        int random = rand() % maxVal;
        int l = 0, r = range.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (random <= range[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        return range[l] == random ? l : r;
    }
private:
    vector<int> range;
};
