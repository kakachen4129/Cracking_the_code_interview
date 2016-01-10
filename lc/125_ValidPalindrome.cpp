class Solution {
public:
    bool isNumber(const char c){
        return c >= '0' && c <= '9';
    }
    bool isLowerCase(const char c){
        return c <= 'z' && c >= 'a';
    }
    bool isUpperCase(const char c){
        return c <= 'Z' && c >= 'A';
    }
    char convertLower(const char c){
        if (isUpperCase(c))    return c - 'A' + 'a';
        return c;
    }
    bool equal(const char c1, const char c2){
        return convertLower(c1) == convertLower(c2);
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (1){
            while (i <= j && (!isLowerCase(s[i]) && !isUpperCase(s[i]) && !isNumber(s[i])))
                i++;
            while (i <= j && (!isLowerCase(s[j]) && !isUpperCase(s[j]) && !isNumber(s[j])))
                j--;
            if (i > j)
                return true;
            if (!equal(s[i++], s[j--]))
                return false;
        }
    }
};