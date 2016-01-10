class Solution {
public:
    int countDigitOne(int n) {
        long long t = 1;
        int left, right;
        int ret = 0;
        while (n >= t){
            left = n / t;
            right = n % t;
            int mid = left % 10;
            if (mid < 1){
                ret += left/10 * t;
            } else if (mid == 1){
                ret += left/10 * t + right + 1;
            } else if (mid > 1){
                ret += (left/10 + 1) * t;
            }
            // be careful for t overflow
            t = t * 10;
        }
        return ret;
    }
};