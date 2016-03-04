class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        unordered_set<char> dup;
        for (int i = 0; i < 9; i++){
            dup.clear();
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    if (dup.find(board[i][j]) != dup.end())
                        return false;
                    dup.insert(board[i][j]);
                }
            }
        }
    
        for (int j = 0; j < 9; j++){
            dup.clear();
            for (int i = 0; i < 9; i++){
                if (board[i][j] != '.'){
                    if (dup.find(board[i][j]) != dup.end())
                        return false;
                    dup.insert(board[i][j]);
                }
            }
        }    
    
        for (int i = 0; i < 9; i += 3){
            for (int j = 0; j < 9; j += 3){
                dup.clear();
                for (int ii = 0; ii < 3; ii++){
                    for (int jj = 0; jj < 3; jj++){
                        if (board[i+ii][j+jj] != '.'){
                        if (dup.find(board[i+ii][j+jj]) != dup.end())
                            return false;
                        dup.insert(board[i+ii][j+jj]);
                        }
                    }
                }
            }
        }
        return true;    
    }
};
