class Solution {
public:
    void getCom(vector<vector<int>> &ret, const vector<int> &vec, int target, 
        vector<int> &cur, int sum, int pos){
        if (sum > target){
            return;
        } else if (sum == target){
            ret.push_back(cur);
            return;
        } else{
            for (int i = pos; i < vec.size(); i++){
                cur.push_back(vec[i]);
                getCom(ret, vec, target, cur, sum+vec[i], i);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> cur;
        vector<vector<int>> ret;
        sort(candidates.begin(), candidates.end());
        getCom(ret, candidates, target, cur, 0, 0);
        return ret;
    }
};