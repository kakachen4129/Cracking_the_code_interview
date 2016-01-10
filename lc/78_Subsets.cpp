class Solution {
    private:
    void getSubsets(vector<vector<int>> &ret, vector<int> &cur, const vector<int> &nums, int pos){
        if (pos >= nums.size()) return;
        for (int i = pos; i < nums.size(); i++){
            cur.push_back(nums[i]);
            ret.push_back(cur);
            getSubsets(ret, cur, nums, i+1);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        ret.push_back(cur);
        getSubsets(ret, cur, nums, 0);
        return ret;
    }
};