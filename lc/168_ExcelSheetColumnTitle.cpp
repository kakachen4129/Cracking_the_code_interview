class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while (n != 0){
            int t = (n - 1) % 26;
            ret += 'A' + t;
            n = (n - 1) / 26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};