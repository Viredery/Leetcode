class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        std::sort(boxTypes.begin(), boxTypes.end(), 
                  [](auto& l, auto&r) {
                      return l[1] > r[1];
                  });
        int max_units = 0;
        int left_truck_size = truckSize;
        for (int i = 0; i != boxTypes.size(); ++i) {
            int acceptable_size = std::min(left_truck_size, boxTypes[i][0]);
            max_units += acceptable_size * boxTypes[i][1];
            left_truck_size -= acceptable_size;
            if (left_truck_size == 0) {
                break;
            }
        }
        return max_units;
    }
};
