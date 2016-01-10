class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++){
            if (i == 0){
                dp[i] = nums[i];
            } else if (i == 1){
                dp[i] = max(nums[i], nums[i-1]);
            } else{
                dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            }
        }
        return dp[n-1];
    }
};