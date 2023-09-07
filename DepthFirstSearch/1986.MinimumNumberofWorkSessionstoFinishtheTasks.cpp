class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        std::sort(tasks.begin(), tasks.end(), std::greater<int>());
        std::vector<int> sessions;
        int min_session = std::numeric_limits<int>::max();
        dfs(tasks, 0, sessionTime, &sessions, &min_session);
        return min_session;
    }
private:
    void dfs(const vector<int>& tasks, int pos, int session_time, std::vector<int>* sessions, int* min_session) {
        if (pos == tasks.size()) {
            *min_session = std::min(*min_session, static_cast<int>(sessions->size()));
            return;
        }
        if (sessions->size() >= *min_session) {
            return;
        }
        for (int i = 0; i != sessions->size(); ++i) {
            if (i > 0 && sessions->at(i) ==  sessions->at(i - 1)) {
                continue;
            }
            if (sessions->at(i) + tasks[pos] > session_time) {
                continue;
            }
            sessions->at(i) += tasks[pos];
            dfs(tasks, pos + 1, session_time, sessions, min_session);
            sessions->at(i) -= tasks[pos];
        }
        sessions->push_back(tasks[pos]);
        dfs(tasks, pos + 1, session_time, sessions, min_session);
        sessions->pop_back();
    }
};
