class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int start = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (i+1 >= n || nums[i+1] - nums[i] != 1){
                ret.push_back(convert(nums[start], nums[i]));
                start = i + 1;
            }
        }
        return ret;
    }
    string convert(int a, int b){
        string ret;
        if (a == b) return to_string(a);
        else    return to_string(a) + "->" + to_string(b);
    }
};