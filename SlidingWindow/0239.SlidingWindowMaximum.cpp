class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> pairs;
        vector<int> res;
        int i = 0;
        while (i != k) {
            while (!pairs.empty() && pairs.back().second < nums[i])
                pairs.pop_back();
            pairs.push_back({i, nums[i]});
            i++;
        }
        if (!pairs.empty())
            res.push_back(pairs.front().second);
        
        while (i != nums.size()) {
            if (pairs.front().first == i - k)
                pairs.pop_front();
            while (!pairs.empty() && pairs.back().second < nums[i])
                pairs.pop_back();
            pairs.push_back({i, nums[i]});
            
            res.push_back(pairs.front().second);
            i++;
        }
        return res;
    }
};
