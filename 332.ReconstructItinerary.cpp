class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, vector<pair<string, bool>>> graph;
        for (auto ticket : tickets) {
            auto iter = graph.find(ticket.first);
            if (iter != graph.end()) {
                graph[ticket.first].push_back({ticket.second, false});
            } else {
                graph[ticket.first] = vector<pair<string, bool>>{{ticket.second, false}};
            }
        }
        classcomp comp;
        for (auto it = graph.begin(); it != graph.end(); ++it) {
            sort(it->second.begin(), it->second.end(), comp);
        }
        vector<string> itinerary{"JFK"};
        dfs(graph, itinerary, tickets.size());
        return itinerary;
    }
private:
    struct classcomp {
      bool operator() (const pair<string, bool>& lhs, const pair<string, bool>& rhs) const
      {return lhs.first < rhs.first;}
    };

    bool dfs(unordered_map<string, vector<pair<string, bool>>>& graph, 
             vector<string>& itinerary, 
             int size) {
        if (itinerary.size() == size + 1)
            return true;
        string top = itinerary.back();
        for (int i = 0; i != graph[top].size(); i++) {
            if (graph[top][i].second == true)
                continue;
            graph[top][i].second = true;
            itinerary.push_back(graph[top][i].first);
            if (dfs(graph, itinerary, size))
                return true;
            itinerary.pop_back();
            graph[top][i].second = false;
        }
        return false;
    }
};
