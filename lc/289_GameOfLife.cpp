class Solution {
public:
    // in-place:
    // 0->1 set cur = 2;
    // 1->0 set cur = -1;
    int nextStage(vector<vector<int>> &board, int i, int j, int m, int n){
        int sum = 0;
        for (int ii = -1; ii <= 1; ii++){
            for (int jj = -1; jj <= 1; jj++){
                if (i+ii < 0 || i + ii >= m || j + jj < 0 || j + jj >= n)
                    continue;
                if (0 == ii && 0 == jj) continue;
                if (board[i+ii][j+jj] == 2) sum += 0;
                else if (board[i+ii][j+jj] == -1)   sum += 1;
                else    sum += board[i+ii][j+jj];
            }
        }
        if (board[i][j] == 0){
            if (sum == 3)   board[i][j] = 2;
        } else{
            if (sum < 2 || sum > 3) board[i][j] = -1;
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                nextStage(board, i, j, m, n);
            }
        }   
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == 2)   board[i][j] = 1;
                else if (board[i][j] == -1) board[i][j] = 0;
            }
        }   
    }
};