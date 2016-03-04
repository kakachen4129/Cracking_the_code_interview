class Solution {
public:
    int searchLeft(const vector<int> &A, int target){
        int l = 0;
        int r = (int)A.size() - 1;
        while (l <= r){
            int mid = (l + r) / 2;
            if (A[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return (A[l] == target) ? l : -1;
    }

    int searchRight(const vector<int> &A, int target){
        int l = 0;
        int r = (int)A.size() - 1;
        while (l <= r){
            int mid = (l + r) / 2;
            if (A[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return (A[r] == target) ? r : -1;
    }

    vector<int> searchRange(vector<int> A, int target) {
        vector<int> ret(2, -1); 
        int l = searchLeft(A, target);
        int r = searchRight(A, target);
        if (l != -1){
            ret[0] = l;
            ret[1] = r;
        }
        return ret;
    }
};
