class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> pos(n, 0);
    vector<int> neg(n, 0);
    pos[0] = nums[0];
    neg[0] = (nums[0] <= 0) ? nums[0] : 0;
    int ret = nums[0];
    for (int i = 1; i < n; i++){
        if (nums[i] >= 0){
            pos[i] = max(nums[i], nums[i] * pos[i-1]);
            neg[i] = min(nums[i], nums[i] * neg[i-1]);
        } else{
            pos[i] = max(nums[i], nums[i] * neg[i-1]);
            neg[i] = min(nums[i], nums[i] * pos[i-1]);
        }
        ret = max(pos[i], ret);
    }
    return ret;
}
};