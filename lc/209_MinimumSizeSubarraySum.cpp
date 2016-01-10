class Solution {
public:
    // sliding window O(n)
    // here is O(nlog(n)) solution
    // common trick : array --> sum_array, afterwards, use binary search
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n+1, 0);
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i-1] + nums[i-1];
        int min = n + 1;
        for (int i = 0; i <= n; i++){
            int target = sum[i] + s;
            int idx = findFirst(sum, target, i, n);
            if (idx <= n && idx - i < min)
                min = idx - i;
        }
        return min == n+1 ? 0 : min;
    }
    int findFirst(const vector<int> &vec, int target, int l, int r){
        while (l <= r){
            int mid = l + (r-l)/2;
            if (vec[mid] < target){
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        return l;
    }
};