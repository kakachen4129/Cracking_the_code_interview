class Solution {
public:
    void permuteUniqueHelper(vector<vector<int> > &ret, vector<int> &num, int pos){
        if (pos == num.size()){
            ret.push_back(num);
            return;
        }
        unordered_set<int> swapped;
        for (int i = pos; i < num.size(); i++){
            if (swapped.find(num[i]) == swapped.end()){
                swapped.insert(num[i]);
                swap(num[i], num[pos]);
                permuteUniqueHelper(ret, num, pos+1);
                swap(num[i], num[pos]);
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ret;
        sort(num.begin(), num.end());
        permuteUniqueHelper(ret, num, 0);
        return ret;
    }
};
