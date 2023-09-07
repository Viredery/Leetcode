class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        std::sort(jobs.begin(), jobs.end(), std::greater<int>());
        int min_time = std::numeric_limits<int>::max();
        std::vector<int> workers(k, 0);
        dfs(jobs, 0, &workers, &min_time);
        return min_time;
    }
private:
    void dfs(const std::vector<int>& jobs, int job_num, std::vector<int>* workers, int* min_time) {
        if (job_num == jobs.size()) {
            *min_time = std::min(*min_time, *std::max_element(workers->begin(), workers->end()));
            return;
        }
        for (int i = 0; i != workers->size(); ++i) {
            if (i > 0 && workers->at(i) == workers->at(i - 1)) {
                continue;
            }
            if ((*workers)[i] + jobs[job_num] >= *min_time) {
                continue;
            }
            (*workers)[i] += jobs[job_num];
            dfs(jobs, job_num + 1, workers, min_time);
            (*workers)[i] -= jobs[job_num];
        }
    }
};
