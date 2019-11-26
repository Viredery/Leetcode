class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        
        map<int, vector<pair<int, int>>> mapped;
        
        for (int i = 0; i != nums.size(); i++)
            for (int j = i + 1; j != nums.size(); j++) 
                mapped[target - nums[i] - nums[j]].push_back({i, j});

        int i = 0;
        while (i < nums.size()) {
            int j = i + 1;
            while (j < nums.size()) {

                int tmp = nums[i] + nums[j];
                if (mapped.find(tmp) != mapped.end()) {
                    int k = 0;
                    while (k < mapped[tmp].size()) {
                        auto idx = mapped[tmp][k];
                        if (i >= idx.first || j >= idx.first) {
                            k++;
                            continue;
                        }
                        res.push_back({nums[i], nums[j], 
                                       nums[idx.first], nums[idx.second]});
                        k++;
                        while (k < mapped[tmp].size() && 
                               (nums[mapped[tmp][k].first] == nums[mapped[tmp][k-1].first] ||
                                nums[mapped[tmp][k].second] == nums[mapped[tmp][k-1].second]))
                            k++;
                    }
                }
                j++;
                while (j < nums.size() && nums[j-1] == nums[j])
                    j++;
            }
            i++;
            while (i < nums.size() && nums[i-1] == nums[i])
                i++;
        }
        

        return res;
    }
};
