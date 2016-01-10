class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        if (n == 0) return ret;
        dfs(ret, nums, 0, n);
        return ret;
    }
    
    void dfs(vector<vector<int>> &ret, vector<int> &nums, int pos, int n){
        if (pos >= n){
            ret.push_back(nums);
            return;
        }
        for (int i = pos; i < n; i++){
            swap(nums[pos], nums[i]);
            dfs(ret, nums, pos+1, n);
            swap(nums[pos], nums[i]);
        }
    }
};