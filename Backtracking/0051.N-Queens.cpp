class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> solutions;
        std::vector<int> column_idxs(n, -1);
        Backtracking(0, &column_idxs, &solutions);
        return solutions;
    }
private:
    void Backtracking(int row, 
                      std::vector<int>* column_idxs, 
                      std::vector<std::vector<std::string>>* solutions) const {
        if (row == column_idxs->size()) {
            RecordSolution(*column_idxs, solutions);
            return;
        }
        for (int i = 0; i != column_idxs->size(); ++i) {
            if (!IsValid(*column_idxs, row, i)) {
                continue;
            }
            (*column_idxs)[row] = i;
            Backtracking(row + 1, column_idxs, solutions);
            (*column_idxs)[row] = -1;
        }
    }

    void RecordSolution(const std::vector<int>& column_idxs, 
                        std::vector<std::vector<std::string>>* solutions) const {
        const std::string empty_spaces(column_idxs.size(), '.');
        std::vector<std::string> solution(column_idxs.size(), empty_spaces);
        for (int i = 0; i != column_idxs.size(); ++i) {
            solution[i][column_idxs[i]] = 'Q';
        }
        solutions->push_back(std::move(solution));
    }

    bool IsValid(const std::vector<int>& column_idxs, int row, int col) const {
        for (int i = 0; i < row; ++i) {
            if (column_idxs[i] == col) {
                return false;
            }
        }
        for (int i = 0; i < row; ++i) {
            if (col - row + i >= 0 && column_idxs[i] == col - row + i) {
                return false;
            }
        }
        for (int i = 0; i < row; ++i) {
            if (col + row - i < column_idxs.size() && column_idxs[i] == col + row - i) {
                return false;
            }
        }
        return true;
    }
};
