class Solution {
public:
int jump(int A[], int n) {
    int count = 0;
    int lastMax = 0;    // 上一步能到的最远点+1
    int curMax = 0;     // 当前步数能到的最远点
    if (n == 1)
        return 0;
    while (lastMax <= curMax){
        int tmp1 = lastMax;
        int tmp2 = curMax;
        for (int i = tmp1; i <= tmp2; i++){
            if (i + A[i] >= n - 1)
                return count+1;
            if (i + A[i] > curMax)
                curMax = i + A[i];
        }
        lastMax = tmp2 + 1;
        count++;
    }
    return 0;
}
};
