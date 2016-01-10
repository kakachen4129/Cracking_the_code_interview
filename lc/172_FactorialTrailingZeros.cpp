class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        long t = 5;
        while (n/t > 0){
            cnt += n/t;
            t = t*5;
        }
        return cnt;
    }
};