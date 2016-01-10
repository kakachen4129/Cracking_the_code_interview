class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ret;
        if (n == 0) return ret;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int len = 1; len <= n; len++){
            for (int i = 0; i + len - 1 < n; i++){
                if (len == 1){
                    dp[i][i+len-1] = true;
                } else if (len == 2){
                    dp[i][i+len-1] = (s[i] == s[i+len-1]);
                } else{
                    dp[i][i+len-1] = (s[i] == s[i+len-1] && dp[i+1][i+len-2]);
                }
            }
        }
        vector<string> vec;
        dfs(ret, vec, dp, 0, s);
        return ret;
    }

    void dfs(vector<vector<string>> &ret, vector<string> &vec, vector<vector<bool>> &dp, int pos, string s){
        if (pos >= s.size()){
            ret.push_back(vec);
            return;
        }
        for (int len = 1; pos + len - 1 < s.size(); len++){
            if (dp[pos][pos+len-1]){
                string sub = s.substr(pos, len);
                vec.push_back(sub);
                dfs(ret, vec, dp, pos+len, s);
                vec.pop_back();
            }
        }
    }
};