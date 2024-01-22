class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        std::unordered_set<int> visited;
        return canReach(arr, start, &visited);
    }

private:
    bool canReach(vector<int>& arr, int start, std::unordered_set<int>* visited) {
        if (start < 0 || start >= arr.size() || visited->count(start)) {
            return false;
        }
        visited->insert(start);
        return arr[start] == 0 || 
               canReach(arr, start + arr[start], visited) || 
               canReach(arr, start - arr[start], visited);
    }
};
