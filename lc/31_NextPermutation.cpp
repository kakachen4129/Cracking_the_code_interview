class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        bool foundInverted = false;
        int i;
        for (i = n - 1; i > 0; i--){
            if (num[i-1] < num[i]){
                foundInverted  = true;
                break;
            }
        }
        if (foundInverted){
            int tmp;
            int min = INT_MAX;
            for (int j = i; j < n; j++){
                if (num[j] > num[i-1] && num[j] - num[i-1] < min){
                    min = num[j] - num[i-1];
                    tmp = j;
                }
            }
            swap(num[i-1], num[tmp]);
            sort(num.begin() + i, num.end());
        }
        else
            sort(num.begin(), num.end());
    }
};
