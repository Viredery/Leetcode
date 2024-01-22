class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        std::vector<bool> reachable(s.size(), false);
        reachable[0] = true;
        std::deque<int> reachable_indexes;
        reachable_indexes.push_back(0);
        for (int i = 1; i != s.size(); ++i) {
            if (s[i] == '1') {
                continue;
            }
            while (!reachable_indexes.empty() && reachable_indexes.front() < i - maxJump) {
                reachable_indexes.pop_front();
            }
            if (!reachable_indexes.empty() && reachable_indexes.front() <= i - minJump) {
                reachable[i] = true;
                reachable_indexes.push_back(i);
            }
            if (reachable_indexes.empty()) {
                return false;
            }
        }
        return reachable[s.size() - 1];
    }
};
