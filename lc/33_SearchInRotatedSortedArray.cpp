class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0;
        int r = n - 1;
        while (l <= r){
            int mid = (l + r) / 2;
            if (A[mid] == target)
                return mid;
            if (A[l] <= A[mid]){
                if (target < A[mid] && target >= A[l])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else{
                if (target > A[mid] && target <= A[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};
