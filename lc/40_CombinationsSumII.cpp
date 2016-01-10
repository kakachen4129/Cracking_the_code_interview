class Solution {
public:
    void getCom(vector<vector<int>> &ret, vector<int> &cur, const vector<int> &vec,
        int pos, int sum, int target){
        if (sum > target){
            return;
        } else if (sum == target){
            ret.push_back(cur);
            return;
        } else{
            for (int i = pos; i < vec.size(); i++){
                if (i != pos && vec[i] == vec[i-1])
                    continue;
                cur.push_back(vec[i]);
                getCom(ret, cur, vec, i+1, sum+vec[i], target);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        vector<vector<int>> ret;
        getCom(ret, cur, candidates, 0, 0, target);
        return ret;
    }
};