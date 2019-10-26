class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        for (vector<int>& prerequisity : prerequisites)
            visited[prerequisity[0]]++;
        queue<int> que;
        for (int i = 0; i != numCourses; i++)
            if (!visited[i])
                que.push(i);
        int size = 0;
        while (!que.empty()) {
            int front = que.front();
            que.pop();
            size++;
            for (vector<int>& prerequisity : prerequisites)
                if (prerequisity[1] == front && --visited[prerequisity[0]] == 0)
                    que.push(prerequisity[0]);
        }
        return size == numCourses;
    }
};
