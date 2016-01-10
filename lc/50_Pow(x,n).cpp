class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        long long tmp = abs((long long)n);
        return n < 0 ? 1.0 / getPow(x, tmp) : getPow(x, tmp);
    }
private:
    double getPow(double x, long long t){
        if (t == 1) return x;
        double tmp = getPow(x, t/2);
        return t % 2 == 0 ? tmp * tmp : tmp * tmp * x;
    }
};