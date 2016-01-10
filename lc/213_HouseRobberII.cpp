class Solution {
public:
    // convert the circle DP into two sub array, [0,n-1) and [1,n)
    int getMaxVal(const vector<int> &nums, int s, int e){
        int n = e - s;
        vector<int> dp(n, 0);
        for (int i = s; i < e; i++){
            if (i == s){
                dp[i-s] = nums[i];
            } else if (i - s == 1){
                dp[i-s] = max(nums[i-1], nums[i]);
            } else{
                dp[i-s] = max(dp[i-s-2] + nums[i], dp[i-s-1]);
            }
        }
        return dp.back();
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(getMaxVal(nums, 0, n-1), getMaxVal(nums, 1, n));
    }
};