class Solution {
public:
    int minJumps(vector<int>& arr) {
        // Build a dictionary of same values.
        std::unordered_map<int, std::vector<int>> edges;
        for (int i = 0; i != arr.size(); ++i) {
            edges[arr[i]].push_back(i);
        }
        std::unordered_set<int> visited = {0};
        std::queue<int> indexes;
        indexes.push(0);
        int step = 0;
        while (!indexes.empty()) {
            const int size = indexes.size();
            for (int i = 0; i != size; ++i) {
                int idx = indexes.front();
                indexes.pop();
                if (idx == arr.size() - 1) {
                    return step;
                }
                for (const auto& next_idx : edges[arr[idx]]) {
                    if (visited.count(next_idx)) {
                        continue;
                    }
                    indexes.push(next_idx);
                    visited.insert(next_idx);
                }
                edges.erase(arr[idx]);
                if (!visited.count(idx + 1) && idx + 1 < arr.size()) {
                    indexes.push(idx + 1);
                    visited.insert(idx + 1);
                }
                if (!visited.count(idx - 1) && idx - 1 >= 0) {
                    indexes.push(idx - 1);
                    visited.insert(idx - 1);
                }

            }
            step += 1;
        }
        return 0;
    }
};
