class Solution {
public:
int findKthElement(int A[], int m, int B[], int n, int k){
    if (m < n)
        return findKthElement(B, n, A, m, k);
    if (n == 0)
        return A[k-1];
    if (k == 1)
        return min(A[0], B[0]);
    int ib = min(n, k/2);   // ib=n的时候下次n有可能为0；ib=k/2的时候下次k有可能等于1，k-k/2最后只可能等于1，不可能等于0.
    int ia = k - ib;        // 为什么这里要用k-ib想过没有？因为要保证加起来等于K，否则A[ia-1] == B[ib-1]时不能return
    if (A[ia-1] < B[ib-1])
        return findKthElement(A+ia, m-ia, B, n, k-ia);
    else if (A[ia-1] > B[ib-1])
        return findKthElement(A, m, B+ib, n-ib, k-ib);
    else
        return A[ia-1];
}
double findMedianSortedArrays(int A[], int m, int B[], int n) {    
    int N = m + n;
    if (N % 2 == 0)
        return (findKthElement(A, m, B, n, N/2+1) + findKthElement(A, m, B, n, N/2)) / 2.0;
    else
        return findKthElement(A, m, B, n, N/2+1) * 1.0;  
}
};