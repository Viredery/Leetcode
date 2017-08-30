class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        deque<pair<int, int>> prerequisitesDeque(prerequisites.begin(), prerequisites.end());
        unordered_set<int> courses;
        int finishedCourse = -1;
        while (finishedCourse != courses.size()) {
            finishedCourse = courses.size();
            vector<bool> unfinished_courses(numCourses, false);
            for (auto prerequisity : prerequisites) {
                if(courses.find(get<1>(prerequisity)) == courses.end())
                    unfinished_courses[get<0>(prerequisity)] = true;
            }
            for (int i = 0; i != numCourses; i++) {
                if (unfinished_courses[i] == false)
                    courses.insert(i);
            }
        }
        return finishedCourse == numCourses;
    }
};