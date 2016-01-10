class Solution {
public:
    const string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        int n = digits.size();
        if (n == 0) return ret;
        string cur;
        getCbs(digits, 0, cur, ret, n);
        return ret;
    }
    
    void getCbs(const string &digits, int pos, string cur, vector<string> &ret, int n){
        if (pos >= n){
            ret.push_back(cur);
            return;
        }
        int idx = digits[pos] - '0';
        for (const auto &ch : map[idx])
            getCbs(digits, pos+1, cur+ch, ret, n);
    }
};