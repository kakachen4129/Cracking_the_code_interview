class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) return 0;
        long long l = 1, r = x;
        while (l <= r){
            long long mid = l + (r - l) / 2;
            long long tmp = mid * mid;
            if (tmp == x){
                return mid;
            } else if (tmp < x){
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        return r;
    }
};