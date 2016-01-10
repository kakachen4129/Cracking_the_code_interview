class Solution {
public:
    // reverse direction, from bottom-right to top-left BFS 
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if (m == 0) return 0;
        int n = dungeon[0].size();
        vector<vector<int>> minHP(m, vector<int>(n, -1));
        vector<vector<int>> visited(m, vector<int>(n, false));
        queue<pair<int,int>> q;
        visited[m-1][n-1] = true;
        q.push(make_pair(m-1, n-1));
        minHP[m-1][n-1] = dungeon[m-1][n-1] > 0 ? 1 : 1 - dungeon[m-1][n-1];
        while (q.empty() != true){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i - 1 >= 0){
                if (visited[i-1][j] == false){
                    q.push(make_pair(i-1, j));
                    visited[i-1][j] = true;
                }
                int tmp = max(minHP[i][j] - dungeon[i-1][j], 1);
                if (minHP[i-1][j] == -1 || tmp < minHP[i-1][j])
                    minHP[i-1][j] = tmp;
            }
            if (j - 1 >= 0){
                if (visited[i][j-1] == false){
                    q.push(make_pair(i, j-1));
                    visited[i][j-1] = true;
                } 
                int tmp = max(minHP[i][j] - dungeon[i][j-1], 1);
                if (minHP[i][j-1] == -1 || tmp < minHP[i][j-1])
                    minHP[i][j-1] = tmp;
            }
        }
        return minHP[0][0];
    }
};