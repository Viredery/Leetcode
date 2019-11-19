class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size();
        while (l < r) {
            int mid = l + (r - l + 1 >> 1);
            if (citations[citations.size() - mid] >= mid)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};
