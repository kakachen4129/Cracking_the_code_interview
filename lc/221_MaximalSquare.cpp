class Solution {
public:
    // this method also works
    /*void init(const vector<vector<char>> &matrix, int m, int n, 
        vector<vector<int>> &v, vector<vector<int>> &h){
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                h[i+1][j+1] = h[i+1][j] + matrix[i][j] - '0';  
            }
        }
        for (int j = 0; j < n; j++){
            for (int i = 0; i < m; i++){
                v[i+1][j+1] = v[i][j+1] + matrix[i][j] - '0';
            }
        }
    }
    int getWidth(const vector<vector<int>> &v, const vector<vector<int>> &h, int m, int n, int i, int j){
        int w = 1;
        while (i < m && j < n){
            if (h[i+1][j+1] - h[i+1][j+1-w] == w && v[i+1][j+1] - v[i+1-w][j+1] == w){
                i++;
                j++;
                w++;
            } else{
                break;
            }
        }
        return w-1;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> h(m+1, vector<int>(n+1, 0));
        vector<vector<int>> v(m+1, vector<int>(n+1, 0));
        init(matrix, m, n, v, h);
        int max = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == '1'){
                    int w = getWidth(v, h, m, n, i, j);
                    max = max > w ? max : w;
                }
            }
        }
        return max * max;
    }*/
    
    // using dp, dp[x][y] = min{dp[x-1][y], dp[x][y-1], dp[x-1][y-1]} + 1
    // (x, y) denotes the right-down corner point, dp[x][y] denotes the max width
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j] - '0';
        for (int i = 0; i < m; i++)
            dp[i][0] = matrix[i][0] - '0';
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                if (matrix[i][j] == '1'){
                    dp[i][j] = min3(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1;
                } else{
                    dp[i][j] = 0;
                }
            }
        }
        int max = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (dp[i][j] > max)
                    max = dp[i][j];
            }
        }
        return max * max;
    }
    int min3(int a, int b, int c){
        int tmp = a < b ? a : b;
        return tmp < c ? tmp : c;
    }
};