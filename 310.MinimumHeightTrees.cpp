class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1)
            return {0};
        if (n == 2)
            return {0, 1};
        vector<unordered_set<int>> graph(n, unordered_set<int>());
        for (auto edge : edges) {
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }
        list<int> leaves;
        for (int i = 0; i != n; i++)
            if (graph[i].size() == 1)
                leaves.push_back(i);
        int numNode = n - leaves.size();
        while (numNode > 2) {
            list<int> newLeaves;
            for (auto leaf : leaves) {
                int node = *graph[leaf].begin();
                graph[node].erase(leaf);
                graph[leaf].clear();
                if (graph[node].size() == 1)
                    newLeaves.push_back(node);
            }
            numNode = numNode - newLeaves.size();
            leaves = move(newLeaves);
        }
        vector<int> res;
        for (int i = 0; i != n; i++)
            if (graph[i].size() > 1)
                res.push_back(i);
        return res;
    }
};
