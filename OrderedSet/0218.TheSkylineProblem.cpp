class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        std::vector<std::vector<int>> res;
        std::multiset<std::pair<int, int>> points;
        for (const auto& building : buildings) {
            points.emplace(building[0], -building[2]);
            points.emplace(building[1], building[2]);
        }
        std::multiset<int> heights{0};
        std::pair<int,int> curr{0,0};
        for (const auto& [pos, height] : points) {
            if (height < 0) {
                heights.insert(-height);
            } else {
                // Only one element is removed even if there are multiple
                // elements with the same value.
                heights.erase(heights.find(height));  
            }
            if (curr.second != *heights.rbegin()) {
                curr = {pos, *heights.rbegin()};
                res.push_back({pos, *heights.rbegin()});
            }
        }
        return res;
    }
};
