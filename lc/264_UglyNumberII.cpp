class Solution {
public:
    int nthUglyNumber(int n) {
        queue<long long> q1, q2, q3;
        int cnt = 1;
        if (n <= 0) return 0;
        q1.push(2);
        q2.push(3);
        q3.push(5);
        int ret = 1;
        while (1){
            if (cnt == n)   return ret;
            long long a1 = q1.front();
            long long a2 = q2.front();
            long long a3 = q3.front();
            if (a1 < a2 && a1 < a3){
                ret = a1;
                q1.pop();
                q1.push(a1*2);
                q2.push(a1*3);
                q3.push(a1*5);
            } else if (a2 < a1 && a2 < a3){
                ret = a2;
                q2.pop();
                q2.push(a2*3);
                q3.push(a2*5);
            } else if (a3 < a1 && a3 < a2){
                ret = a3;
                q3.pop();
                q3.push(a3*5);
            }
            cnt++;
        }
        return 0;
    }
};