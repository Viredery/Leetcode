class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;
        
        // Step One: get the next state per cell
        for (int i = 0; i != board.size(); i++) {
            for (int j = 0; j != board[i].size(); j++) {
                int live_cell = 0;
                for (int ii = max(i-1, 0); ii <= min(i+1, int(board.size()-1)); ii++)
                    for (int jj = max(j-1, 0); jj <= min(j+1, int(board[i].size()-1)); jj++)
                        live_cell += int(board[ii][jj] & 1);
                
                if (board[i][j] & 1) { // True when board[i][j] = 1 or 3 or 5 (that is, current state is live)
                    if (live_cell == 3 || live_cell == 4)
                        board[i][j] = 3; // state 3(11): current state: live, next state: live
                    else
                        board[i][j] = 5; // state 5(101): current state: live, next state: dead
                } else { // False when board[i][j] = 0 or 2 or 4 (that is, current state is dead)
                    if (live_cell == 3)
                        board[i][j] = 2; // state 2(10): current state: dead, next state: live
                    else
                        board[i][j] = 4; // state 4(100): current state: dead, next state: dead
                }
            }
        }
        // Step Two: update
        for (int i = 0; i != board.size(); i++)
            for (int j = 0; j != board[i].size(); j++)
                board[i][j] = board[i][j] & 2 ? 1 : 0;
    }
};