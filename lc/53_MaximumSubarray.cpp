class Solution {
public:
    // this method also works
    /*int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> max(n, 0);
        max[0] = nums[0];
        int ret = max[0];
        for (int i = 1; i < n; i++){
            max[i] = (max[i-1] < 0) ? nums[i] : nums[i] + max[i-1];
            if (max[i] > ret)   ret = max[i];
        }
        return ret;
    }*/
    
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        return getMax(nums, 0, n-1);
    }
    int getRightMax(const vector<int> &nums, int s, int r){
        int max = nums[s];
        int sum = nums[s];
        for (int i = s + 1; i <= r; i++){
            sum += nums[i];
            if (sum > max)  max = sum;
        }
        return max;
    }
    int getLeftMax(const vector<int> &nums, int s, int l){
        int max = nums[s];
        int sum = nums[s];
        for (int i = s - 1; i >= l; i--){
            sum += nums[i];
            if (sum > max)  max = sum;
        }
        return max;
    }
    int getMax(const vector<int> &nums, int l, int r){
        if (l == r) return nums[l];
        int mid = l + (r - l)/2;
        int l_max = getMax(nums, l, mid);
        int r_max = getMax(nums, mid+1, r);
        int m_max = getRightMax(nums, mid+1, r) + getLeftMax(nums, mid, l);
        return max(max(l_max, r_max), m_max);
    }
};