class Solution {
public:
    /* method 1: three rotates
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }*/
    
    /* method 2: rotate one by one, TLE here
    void rotateByOne(vector<int> &nums){
        int n = nums.size();
        int tmp = nums[n-1];
        for (int i = n - 2; i >= 0; i--)
            nums[i+1] = nums[i];
        nums[0] = tmp;
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k = k % n;
        for (int i = 0; i < k; i++)
            rotateByOne(nums);
    }*/
    
    /* method three: ordinary method, extra space
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k = k % n;
        vector<int> tmp;
        for (int i = n - k; i < n; i++)
            tmp.push_back(nums[i]);
        for (int i = n - k - 1; i >= 0; i--)
            nums[i+k] = nums[i];
        for (int i = 0; i < k; i++)
            nums[i] = tmp[i];
    }*/
    
    //method four: rorate k positions one time
    // group into gcd(n,k) groups
    int gcd (int a, int b){
        int c;
        while ( a != 0 ) {
            c = a; a = b%a;  b = c;
        }
        return b;
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k = k % n;
        int t = gcd(n,k);
        for (int i = 0; i < t; i++){
            int idx = i;
            int cur = nums[i];
            while ((idx + k) % n != i){
                swap(nums[(idx+k)%n], cur);
                idx = (idx + k) % n;
            }
            nums[i] = cur;
        }
    }
};