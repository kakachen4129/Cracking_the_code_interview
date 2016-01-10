class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size();
        int sum = 0;    
        for (int i = n - 1; i >= 0; i--)
            sum += (s[i] - 'A' + 1) * pow(26, n-1-i);
        return sum;
    }
};