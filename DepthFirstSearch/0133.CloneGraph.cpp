/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (dict.find(node) != dict.end())
            return dict[node];
        Node* cloneNode = new Node(node->val, {});
        dict[node] = cloneNode;
        for (int i = 0; i != node->neighbors.size(); i++)
            cloneNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        return cloneNode;
    }
private:
    unordered_map<Node*, Node*> dict;
};
