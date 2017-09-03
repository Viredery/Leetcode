class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> prerequisity_number(numCourses, 0);
        vector<unordered_set<int>> graph(numCourses);
        for (auto prerequisity : prerequisites) {
            prerequisity_number[prerequisity.first]++;
            graph[prerequisity.second].insert(prerequisity.first);
        }
        vector<int> order;
        vector<int> visited(numCourses, false);
        while (true) {
            vector<int> que;
            for (int i = 0; i != numCourses; i++) {
                if (prerequisity_number[i] == 0 && visited[i] == false) {
                    order.push_back(i);
                    que.push_back(i);
                    visited[i] = true;
                }
            }
            if (que.empty()) {
                return order.size() == numCourses ? order : vector<int>();
            }
            for (int j : que)
                for (int k : graph[j])
                   prerequisity_number[k]--;
        }
    }
};