class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int l = 0, r = n - 1;
        // first make sure whether the array has been rotated
        if (nums[l] < nums[r])  return nums[0];
        while (r - l > 1){
            int mid = l + (r-l)/2;
            if (nums[l] < nums[mid]){
                l = mid;
            } else{
                r = mid;
            }
        }
        // for rotated array, always return nums[r]
        return nums[r];
    }
};