class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        std::vector<std::vector<int>> intersected;
        int first_pos = 0;
        int second_pos = 0;
        while (first_pos != firstList.size() && second_pos != secondList.size()) {
            const int start = std::max(firstList[first_pos][0], secondList[second_pos][0]);
            const int end = std::min(firstList[first_pos][1], secondList[second_pos][1]);
            if (start <= end) {
                intersected.push_back({start, end});
            } if (firstList[first_pos][1] > secondList[second_pos][1]) {
                second_pos++;
            } else {
                first_pos++;
            }
        }
        return intersected;
    }
};
