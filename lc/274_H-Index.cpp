bool cmp(const int &a, const int &b){
    return a > b;
}

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), cmp);
        int n = citations.size();
        int i;
        for (i = 0; i < n; i++){
            if (citations[i] < i + 1)
                break;
        }
        return i;
    }
};