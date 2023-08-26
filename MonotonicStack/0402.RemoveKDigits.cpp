class Solution {
public:
    string removeKdigits(string num, int k) {
        std::vector<char> increasing_nums;
        int num_removed = 0;
        for (const auto& digit : num) {
            while (num_removed != k && !increasing_nums.empty() && increasing_nums.back() > digit) {
                increasing_nums.pop_back();
                num_removed++;
            }
            increasing_nums.push_back(digit);
        }
        while (!increasing_nums.empty() && num_removed != k) {
            increasing_nums.pop_back();
            num_removed++;
        }
        auto begin = increasing_nums.begin();
        while (begin != increasing_nums.end() && *begin == '0') {
            begin++;
        }
        return begin == increasing_nums.end() ? "0" : std::string{begin, increasing_nums.end()};
    }
};
