class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<int> num_prerequisites(numCourses, 0);
        for (const auto& prerequisite : prerequisites) {
            num_prerequisites[prerequisite[0]]++;
        }

        std::queue<int> order;
        for (int i = 0; i != numCourses; ++i) {
            if (num_prerequisites[i]) {
                continue;
            }
            order.push(i);
        }

        int num_finished = 0;
        while (!order.empty()) {
            const int course = order.front();
            order.pop();
            num_finished++;
            for (const auto& prerequisite : prerequisites) {
                if (prerequisite[1] == course && --num_prerequisites[prerequisite[0]] == 0) {
                    order.push(prerequisite[0]);
                }
            }
        }
        return num_finished == numCourses;
    }
};
