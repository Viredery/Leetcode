class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        std::vector<std::pair<int, int>> heights;
        heights.reserve(buildings.size() * 2);
        for (const auto& building : buildings) {
            heights.emplace_back(building[0], building[2]);
            heights.emplace_back(building[1], -building[2]);
        }
        std::sort(heights.begin(), heights.end(), [](auto& l, auto& r) {
            return l.first == r.first ? l.second > r.second : l.first < r.first;
        });

        std::vector<std::vector<int>> skylines;
        std::multiset<int> current_heights;
        int prev_edge = -1;
        for (const auto& [x, height] : heights) {
            // Record the previous outer contour
            if (x != prev_edge && prev_edge >= 0) {
                const int prev_height = current_heights.empty() ? 0 : *current_heights.rbegin();
                if (skylines.empty() || prev_height != skylines.back()[1]) {
                    skylines.push_back({prev_edge, prev_height});
                }
            }
            prev_edge = x;
            // Update priority queues
            if (height > 0) {
                current_heights.insert(height);
            } else {
                current_heights.erase(current_heights.find(-height));
            }
        }
        if (prev_edge > 0) {
            skylines.push_back({prev_edge, 0});
        }
        return skylines;
    }
};
