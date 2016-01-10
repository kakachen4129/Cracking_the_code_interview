class Solution {
public:
    // at most two numbers. so first loop to find the possible two, then second to check it.
    // 1. the init value of a and b does not matter, can be any values.
    // 2. the order of the if else in first loop matters!
    vector<int> majorityElement(vector<int>& nums) {
        int a = 1, b = 1, cnt_a = 0, cnt_b = 0;
        for (auto &x : nums){
            if (x == a){
                cnt_a++;
            } else if (x == b){
                cnt_b++;
            } else if (cnt_a == 0){
                a = x;
                cnt_a = 1;
            } else if (cnt_b == 0){
                b = x;
                cnt_b = 1;
            } else{
                cnt_a--;
                cnt_b--;
            }
        }
        cnt_a = cnt_b = 0;
        for (auto &x : nums){
            if (x == a) cnt_a++;
            else if (x == b) cnt_b++;
        }
        vector<int> ret;
        if (cnt_a > nums.size()/3)  ret.push_back(a);
        if (cnt_b > nums.size()/3)  ret.push_back(b);
        return ret;
    }
};