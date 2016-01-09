class Solution {
public:
    void dfs(int &ret, int remains, int t, int num){
        if (num >= ret) return;
        if (remains == 0){
            if (num < ret)  ret = num;
            return;
        }
        for (int i = t; i >= 0; i--){
            if (remains >= i * i){
                dfs(ret, remains - i * i, i, num+1);
            }
        }
    }
    int numSquares(int n){
        int t = sqrt(n);
        int ret = INT_MAX;
        dfs(ret, n, t, 0);
        return ret;
    }
    /* method 2
    // using BFS idea, construct the tree from low level 
    // can use pointer to vector, but seems not work well
    void dfs(int &ret, int remains, int pos, int num, const vector<int> &vec){
        if (num >= ret)  return;
        if (remains == 0){
            if (num < ret)  ret = num;
            return;
        }
        for (int i = pos; i >= 0; i--){
            if (remains >= vec[i]){
                dfs(ret, remains - vec[i], i, num+1, vec);
            }
        }
    }
    int numSquares(int n) {
        int ret = INT_MAX;
        vector<int> vec;
        for (int i = 0; i * i <= n; i++)
            vec.push_back(i*i);
        dfs(ret, n, vec.size()-1, 0, vec);
        return ret;
    }*/
    
    /* method 2
    // using BFS idea, construct the tree from low level 
    // can use pointer to vector, but seems not work well
    int numSquares(int n) {
        int t = sqrt(n);
        if (t * t == n) return 1;
        vector<int> vec1;
        unordered_set<int> set;
        for (int i = 1; i <= t; i++){
            vec1.push_back(i*i);
            set.insert(i*i);
        }
        vector<int> vec2 = vec1;
        vector<int> vec3;
        int cnt = 2;
        while (1){
            for (int i = 0; i < vec1.size(); i++){
                for (int j = i; j < vec2.size(); j++){
                    int sum = vec1[i] + vec2[j];
                    if (sum == n)   return cnt;
                    if (set.find(sum) != set.end()) continue;
                    vec3.push_back(sum);
                    set.insert(sum);
                }
            }
            cnt++;
            vec2 = vec3;
            vec3.clear();
        }       
    }*/
};