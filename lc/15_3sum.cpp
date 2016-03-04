class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    sort(num.begin(), num.end());
    vector<int> vec;
    vector<vector<int>> ret;
    for (int i = 0; i < num.size(); i++){
        if (i != 0 && num[i] == num[i-1])
            continue;
        int j = i + 1;
        int k = num.size() - 1;
        while (j < k){
            if (j != i + 1 && num[j] == num[j-1]){
                j++;
                continue;
            }
            int sum = num[i] + num[j] + num[k];
            if (sum < 0)
                j++;
            else if (sum > 0)
                k--;
            else{
                vec.push_back(num[i]);
                vec.push_back(num[j]);
                vec.push_back(num[k]);
                ret.push_back(vec);
                vec.clear();
                j++;
                k--;
            }
        }
    }
    return ret;
}
};
