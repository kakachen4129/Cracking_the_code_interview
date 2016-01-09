class Solution {
public:
    // similar to binary search, O(nlogn)
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 1, j = n;
        while (i < j){
            int mid = i + (j - i) / 2;
            int cnt = getNumber(nums, mid);
            if (cnt <= mid){
                i = mid + 1;
            } else{
                j = mid;
            }
        }
        return i;
    }
    
    int getNumber(const vector<int> &nums, int t){
        int cnt = 0;
        for (const auto &val : nums){
            if (val <= t)
                cnt++;
        }
        return cnt;
    }
};
