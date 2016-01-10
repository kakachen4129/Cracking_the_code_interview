class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int a, cnt = 0;
        int n = nums.size();
        if (n == 0) return -1;
        for (int i = 0; i < n; i++){
            if (cnt == 0){
                cnt++;
                a = nums[i];
            } else{
                if (nums[i] == a)   cnt++;
                else    cnt--;
            }
        }
        return a;
    }
};