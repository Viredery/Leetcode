class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        std::sort(people.begin(), people.end(), cmp());
        vector<vector<int>> res(people.size(), vector<int>());
        for (auto person : people) {
            int pos = 0, c = 0;
            while (c < person[1] || !res[pos].empty()) {
                if (res[pos].empty())
                    c++;
                pos++;
            }
            res[pos] = person;
        }
        return res;
    }

private:
    struct cmp {
        bool operator() (vector<int>& l, vector<int>& r) {
            return l[0] != r[0] ? l[0] < r[0] : l[1] > r[1];
        }
    };
};
