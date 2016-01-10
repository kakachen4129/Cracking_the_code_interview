class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        int i = 0;
        while (i < a.size() || i < b.size()){
            int sum = carry;
            if (i < a.size())
                sum += a[i] - '0';
            if (i < b.size())
                sum += b[i] - '0';
            ret.push_back(sum % 2 + '0');
            carry = sum / 2;
            i++;
        }
        if (carry != 0) ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};