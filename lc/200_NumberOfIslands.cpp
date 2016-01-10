class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ret = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1' && visited[i][j] == false){
                    ret++;
                    getOneIsland(grid, visited, i, j, m, n);
                }
            }
        }
        return ret;
    }
    void getOneIsland(const vector<vector<char>> &grid, vector<vector<bool>>& visited, int i, int j, int m, int n){
        if (i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == '0' || visited[i][j] == true)
            return;
        visited[i][j] = true;
        getOneIsland(grid, visited, i+1, j, m, n);
        getOneIsland(grid, visited, i-1, j, m, n);
        getOneIsland(grid, visited, i, j+1, m, n);
        getOneIsland(grid, visited, i, j-1, m, n);
    }
};