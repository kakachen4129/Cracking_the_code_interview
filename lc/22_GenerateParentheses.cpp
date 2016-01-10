class Solution {
public:
    /*void dfs(vector<string> &ret, string cur, int l, int r, int n){
        if (l == n && r == n){
            ret.push_back(cur);
            return;
        }
        if (l == n){
            dfs(ret, cur+')', l, r+1, n);
        } else if (l == r){
            dfs(ret, cur+'(', l+1, r, n);
        } else{
            dfs(ret, cur+'(', l+1, r, n);
            dfs(ret, cur+')', l, r+1, n);
        }
    }*/
    void dfs(vector<string> &ret, string cur, int l, int r, int n){
        if (r > l || l > n || r > n)    return;
        if (l == n && r == n){
            ret.push_back(cur);
            return;
        }
        dfs(ret, cur+'(', l+1, r, n);
        dfs(ret, cur+')', l, r+1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string cur;
        dfs(ret, cur, 0, 0, n);
        return ret;
    }
};