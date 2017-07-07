/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr)
            return nullptr;
        map<UndirectedGraphNode *, UndirectedGraphNode *> visited;
        return clone(node, visited);
    }
private:
    UndirectedGraphNode *clone(UndirectedGraphNode *node, map<UndirectedGraphNode *, UndirectedGraphNode *>& visited) {
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        visited[node] = newNode;
        for (auto neighbor : node->neighbors) {
            auto iter = visited.find(neighbor);
            if (iter == visited.end()) {
                UndirectedGraphNode *neighborNode = clone(neighbor, visited);
                newNode->neighbors.push_back(neighborNode);
            } else {
                newNode->neighbors.push_back(iter->second);
            }
        }
        return newNode;
    }
};