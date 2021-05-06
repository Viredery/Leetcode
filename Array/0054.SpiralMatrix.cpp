class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        vector<int> spiral_order;
        const int m = matrix.size(), n = matrix[0].size();
        const int circle_num = (min(m, n) + 1) / 2;
        for (int i = 0; i < circle_num; ++i) {
            spiralOrderForCircle(matrix, i, &spiral_order);
        }
        return spiral_order;
    }
private:
    void spiralOrderForCircle(vector<vector<int>>& matrix, 
                              int order_num, 
                              vector<int>* spiral_order) {
        const int top = order_num;
        const int left = order_num;
        const int bottom = matrix.size() - order_num - 1;
        const int right = matrix[0].size() - order_num - 1;
        for (int i = left; i <= right; i++) {
            spiral_order->push_back(matrix[top][i]);
        }
        for (int i = top + 1; i <= bottom; i++) {
            spiral_order->push_back(matrix[i][right]);
        }
        if (top != bottom && left != right) {
            for (int i = right - 1; i >= left; i--) {
                spiral_order->push_back(matrix[bottom][i]);
            }
            for (int i = bottom - 1; i > top; i--) {
                spiral_order->push_back(matrix[i][left]);
            }
        }
    }
};

