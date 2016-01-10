class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n, false);
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= i; j++){
                string substr = s.substr(j, i-j+1);
                if (wordDict.find(substr) != wordDict.end())
                    dp[i] = dp[i] || ((j == 0) ? true : dp[j-1]);
            }
        }
        return dp[n-1];
    }
};
