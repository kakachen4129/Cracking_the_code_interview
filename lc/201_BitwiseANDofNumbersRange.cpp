class Solution {
public:
    int getMostSignificant(int n){
        int cnt = 0;
        while (n != 0){
            n = n >> 1;
            cnt++;
        }
        return cnt;
    }
    int rangeBitwiseAnd(int m, int n) {
        int t1 = getMostSignificant(m);
        int t2 = getMostSignificant(n);
        if (t1 == 0)    return 0;
        if (t1 != t2)   return 0;
        int tmp = 1 << (t1-1);
        return tmp + rangeBitwiseAnd(m-tmp, n-tmp);
    }
};