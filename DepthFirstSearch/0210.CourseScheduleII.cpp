class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graph(numCourses, std::vector<int>{});
        for (const auto& prerequisite : prerequisites) {
            graph[prerequisite[0]].push_back(prerequisite[1]);
        }
        std::vector<NodeStatus> status(numCourses, NodeStatus::kInit);
        std::vector<int> order;
        for (int i = 0; i != numCourses; ++i) {
            if (status[i] != NodeStatus::kInit) {
                continue;
            }
            dfs(graph, i, &status, &order);
        }
        return order.size() == numCourses ? order : vector<int>{};
    }
private:
    enum class NodeStatus {
        kInit,
        kRunning,
        kDone
    };
    
    void dfs(const std::vector<std::vector<int>>& graph, 
             int start,
             std::vector<NodeStatus>* status,
             std::vector<int>* order) const {
        if ((*status)[start] != NodeStatus::kInit) {
            return;
        }
        (*status)[start] = NodeStatus::kRunning;
        for (const auto& idx : graph[start]) {
            if ((*status)[idx] == NodeStatus::kRunning) {
                return;  // loop
            }
            dfs(graph, idx, status, order);
        }
        (*status)[start] = NodeStatus::kDone;
        order->push_back(start);
    }
};
