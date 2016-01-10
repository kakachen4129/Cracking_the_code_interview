class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        int sum = 1;
        for (int i = 0; i < n; i++){
            sum = sum * nums[i];
            ret[i] = sum;
        }
        sum = 1;
        for (int i = n - 1; i >= 1; i--){
            ret[i] = sum * ret[i-1];
            sum = sum * nums[i];
        }
        ret[0] = sum;
        return ret;
    }
};