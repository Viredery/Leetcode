class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<int> num_prerequisites(numCourses, 0);
        for (const auto& prerequisite : prerequisites) {
            num_prerequisites[prerequisite[0]]++;
        }

        std::vector<int> order;
        order.reserve(numCourses);
        for (int i = 0; i != numCourses; ++i) {
            if (num_prerequisites[i]) {
                continue;
            }
            order.push_back(i);
        }

        int cur_pos = 0;
        while (cur_pos != order.size()) {
            const int course = order[cur_pos];
            for (const auto& prerequisite : prerequisites) {
                if (prerequisite[1] == course && --num_prerequisites[prerequisite[0]] == 0) {
                    order.push_back(prerequisite[0]);
                }
            }
            cur_pos++;
        }
        return order.size() == numCourses ? order : vector<int>{};
    }
};
