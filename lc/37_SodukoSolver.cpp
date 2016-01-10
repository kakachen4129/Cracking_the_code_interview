class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        bool solved = false;
        dfs(board, m, n, 0, solved);
    }

    void dfs(vector<vector<char>> &board, int m, int n, int cnt, bool &solved){
        if (cnt >= m * n){
            solved = true;
            return;
        }
        int i = cnt / n;
        int j = cnt % n;
        if (board[i][j] >= '1' && board[i][j] <= '9'){
            dfs(board, m, n, cnt+1, solved);
        } else{
            for (int ch = '1'; ch <= '9'; ch++){
                if (!solved && valid(board, ch, i, j)){
                    board[i][j] = ch;
                    dfs(board, m, n, cnt+1, solved);
                    if (!solved)    board[i][j] = '.';
                }
            }
        }
    }

    bool valid(vector<vector<char>> &board, int ch, int i, int j){
        for (int ii = 0; ii < 9; ii++)
            if (board[ii][j] == ch)
                return false;
        for (int jj = 0; jj < 9; jj++)
            if (board[i][jj] == ch)
                return false;
        int x = (i/3)*3;
        int y = (j/3)*3;
        for (int ii = 0; ii < 3; ii++)
            for (int jj = 0; jj < 3; jj++)
                if (board[x+ii][y+jj] == ch)
                    return false;
        return true;
    }
};