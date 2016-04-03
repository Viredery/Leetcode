class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.begin()->size();
        return search(matrix, 0, 0, m - 1, n - 1, target);
    }
    bool search(vector<vector<int>>& matrix, int ltx, int lty, int rbx, int rby, int target) {
        int mx = (ltx + rbx) / 2, my = (lty + rby) / 2;
        int current_element = matrix[mx][my];
        if(current_element == target)
            return true;
        else if(current_element < target) {
            if(mx + 1 <= rbx && search(matrix, mx + 1, lty, rbx, my, target) == true)
                return true;
            if(my + 1 <= rby && search(matrix, ltx, my + 1, mx, rby, target) == true)
                return true;
            if(mx + 1 <= rbx && my + 1 <= rby && search(matrix, mx + 1, my + 1, rbx, rby, target) == true)
                return true;
        } else {
            if(mx - 1 >= ltx && search(matrix, ltx, my, mx - 1, rby, target) == true)
                return true;
            if(my - 1 >= lty && search(matrix, mx, lty, rbx, my - 1, target) == true)
                return true;
            if(mx - 1 >= ltx && my - 1 >= lty && search(matrix, ltx, lty, mx - 1, my - 1, target) == true)
                return true;
        }
        return false;
    }
};
