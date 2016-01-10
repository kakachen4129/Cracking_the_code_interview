class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<int> map(n, 0);
        dfs(ret, map, 0, n);
        return ret;
    }

    void dfs(vector<vector<string>> &ret, vector<int> &map, int pos, int n){
        if (pos >= n){
            ret.push_back(cvtMap(map, n));
            return;
        }
        for (int i = 0; i < n; i++){
            if (isValid(map, pos, i)){
                map[pos] = i;
                dfs(ret, map, pos+1, n);
            }
        }
    }

    vector<string> cvtMap(const vector<int> &map, int n){
        string s(n, '.');
        vector<string> ret(n, s);
        for (int i = 0; i < n; i++)
            ret[map[i]][i] = 'Q';
        return ret;
    }

    bool isValid(const vector<int> &map, int pos, int t){
        for (int i = 0; i < pos; i++)
            if (map[i] == t)
                return false;
        for (int i = 0; i < pos; i++)
            if (abs(i - pos) == abs(map[i] - t))
                return false;
        return true;
    }
};