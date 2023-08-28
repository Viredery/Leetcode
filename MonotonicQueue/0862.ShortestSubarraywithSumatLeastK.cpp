class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        std::vector<long> sums(nums.size() + 1, 0);
        for (int i = 0; i != nums.size(); ++i) {
            sums[i + 1] = nums[i] + sums[i];
        }
        std::deque<int> increased;
        int shortest_size = -1;
        for (int i = 0; i != sums.size(); ++i) {
            while (!increased.empty() && sums[i] - sums[increased.front()] >= k) {
                const int size = i - increased.front();
                shortest_size = (shortest_size == -1 ? size : std::min(size, shortest_size));
                increased.pop_front();
            }
            while (!increased.empty() && sums[increased.back()] >= sums[i]) {
                increased.pop_back();
            }
            increased.push_back(i);
        }
        return shortest_size;
    }
};
