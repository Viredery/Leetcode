class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> values;
        for (int i = 0; i != nums.size(); i++)
            for (int num : nums[i])
                values.push_back({num, i});
        sort(values.begin(), values.end());
        vector<int> cnt(nums.size(), 0);
        int count = 0;
        int left = 0, right = 0;
        vector<int> minRange = {-100000, 100000};
        while (right < values.size()) {
            cnt[values[right].second]++;
            if (cnt[values[right].second] == 1)
                 count++;
            while (count == nums.size()) {
                int l = values[left].first, r = values[right].first;
                if (r - l < minRange[1] - minRange[0] ||
                    (r - l == minRange[1] - minRange[0] && l < minRange[0]))
                    minRange = vector<int>{l, r};
                
                cnt[values[left].second]--;
                if (cnt[values[left].second] == 0)
                    count--;
                left++;
            }
            right++;
        }
        return minRange;
    }

};
