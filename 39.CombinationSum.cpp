class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> solutions;
        list<int> stack;
        int pos = 0;
        int currentSum = 0;
        while(pos != candidates.size() || !stack.empty()) {
            while (pos == candidates.size() && !stack.empty()) {
                //backtracking
                pos = stack.back();
                stack.pop_back();
                currentSum -= candidates[pos++];
            }
            while (pos != candidates.size() && candidates[pos] + currentSum <= target) {
                currentSum += candidates[pos];
                stack.push_back(pos);
                if (currentSum == target) {
                    vector<int> solution;
                    for (list<int>::iterator iter = stack.begin(); iter != stack.end(); iter++)
                        solution.push_back(candidates[*iter]);
                    solutions.push_back(solution);
                    //backtracking
                    pos = stack.back();
                    stack.pop_back();
                    currentSum -= candidates[pos++];
                    break;
                } 
            }
            if (pos != candidates.size() && candidates[pos] + currentSum > target)
                pos++;
        }
        return solutions;
    }
};