class Solution {
public:
    int superEggDrop(int k, int n) {
        // func(k,n) = 1 +  min_i( max(func(k - 1, i - 1), func(k, n - i)))
        std::vector<std::vector<int>> min_moves(k + 1, std::vector<int>(n + 1, 0));
        return helper(k, n, &min_moves);
    }
    int helper(int k, int n, std::vector<std::vector<int>>* min_moves) {
        if (k == 1) {
            return n;
        }
        if (n <= 1) {
            return n;
        }
        if ((*min_moves)[k][n] > 0) {
            return (*min_moves)[k][n];
        }
        int min_move = n;
        int left = 1;
        int right = n;
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            const int move_w_break = helper(k - 1, mid - 1, min_moves);
            const int move_wo_break = helper(k, n - mid, min_moves);
            min_move = std::min(min_move, std::max(move_w_break, move_wo_break));
            if (move_w_break == move_wo_break) {
                break;
            } else if (move_w_break < move_wo_break) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        (*min_moves)[k][n] = 1 + min_move;
        return (*min_moves)[k][n];
    }
};
