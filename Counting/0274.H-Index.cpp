class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::vector<int> counts(citations.size() + 1, 0);
        for (const auto& citation : citations) {
            if (citation >= citations.size()) {
                counts[citations.size()]++;
            } else {
                counts[citation]++;
            }
        }
        int num_papers = 0;
        for (int i = citations.size() ; i >= 0; --i) {
            num_papers += counts[i];
            if (num_papers >= i) {
                return i;
            }
        }
        return 0;
    }
};
