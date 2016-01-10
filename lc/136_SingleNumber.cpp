class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (const auto &val : nums)
            ret = ret ^ val;
        return ret;
    }
};