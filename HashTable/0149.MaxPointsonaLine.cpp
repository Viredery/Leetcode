class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 2) {
            return points.size();
        }
        int max_count = 1;
        for (int i = 0; i + 1 != points.size(); ++i) {
            auto pairHash = [](const std::pair<int, int>& p) -> size_t {
                return std::hash<int>()(p.first + p.second); 
            };
            unordered_map<std::pair<int, int>, int, decltype(pairHash)> count_dict(0, pairHash);;
            for (int j = i + 1; j != points.size(); ++j) {
                const int x_diff = points[j][0] - points[i][0];
                const int y_diff = points[j][1] - points[i][1];
                if (x_diff == 0) {
                    count_dict[std::make_pair(0, 0)]++;
                } else {
                    const int gcd = getGcd(x_diff, y_diff);
                    count_dict[make_pair(x_diff / gcd, y_diff / gcd)]++;
                }
            }
            for (const auto& item : count_dict) {
                max_count = std::max(max_count, item.second + 1);
            }
        }
        return max_count;
    }
private:

    int getGcd(int a, int b) {
        return b == 0 ? a : getGcd(b, a % b);
    }
};
