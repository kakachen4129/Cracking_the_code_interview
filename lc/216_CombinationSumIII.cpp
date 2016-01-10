class Solution {
public:
    void getCom(vector<vector<int>> &ret, vector<int> &cur, int sum,
        int val, int k, int target){
        int n = cur.size();
        if (n > k){
            return;
        } else if (n == k){
            if (sum == target)
                ret.push_back(cur);
            return;
        } else{
            if (sum >= target)  return;
            for (int i = val; i <= 10 + n - k; i++){
                cur.push_back(i);
                getCom(ret, cur, sum+i, i+1, k, target);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        vector<vector<int>> ret;
        getCom(ret, cur, 0, 1, k, n);
        return ret;
    }
};