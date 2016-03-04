class Solution {
public:
bool canJump(int A[], int n) {
    if (n == 0 || n == 1)    return true;
    int max = A[0];
    for (int i = 1; i < n; i++){
        if (max >= n - 1)
            return true;
        if (i <= max){
            if (i + A[i] > max)
                max = i + A[i];
        } else{
            return false;
        }
    }
}
};
