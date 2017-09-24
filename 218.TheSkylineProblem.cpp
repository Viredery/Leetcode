class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        if (buildings.empty())
            return res;
        priority_queue<pair<int, int>> q;
        q.emplace(0, INT_MAX);
        
        int curPos = 0, buildingPos = 0;
        while (q.size() > 1 || buildingPos < buildings.size()) {
            int end = get<1>(q.top());
            int start = end;
            while (buildingPos < buildings.size() && buildings[buildingPos][0] <= start) {
                start = buildings[buildingPos][0];
                q.emplace(buildings[buildingPos][2], buildings[buildingPos][1]);
                buildingPos++;
            }
            int curPos = min(end, start);
            while (!q.empty() && curPos >= get<1>(q.top()))
                q.pop();
            if (res.empty() || get<1>(res.back()) != get<0>(q.top()))
                res.emplace_back(curPos, get<0>(q.top()));
        }
        return res;
    }
};