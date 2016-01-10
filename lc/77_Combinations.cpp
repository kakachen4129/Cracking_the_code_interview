class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        vector<vector<int>> ret;
        dfs(ret, vec, n, k, 1);
        return ret;
    }

    void dfs(vector<vector<int>> &ret, vector<int> &vec, int n, int k, int num){
        if (vec.size() == k){
            ret.push_back(vec);
            return;
        }
        for (int i = num; i <= n; i++){
            vec.push_back(i);
            dfs(ret, vec, n, k, i+1);
            vec.pop_back();
        }
    }   
};