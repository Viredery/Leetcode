class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        for (int i = citations.size() - 1; i >= 0; i--) {
            if (citations[i] == citations.size() - i)
                return citations[i];
            if (citations[i] < citations.size() - i)
                return citations.size() - i - 1;
        }
        return citations.size();
    }
};