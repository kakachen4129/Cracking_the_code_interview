class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ret;
        if (n == 0) return ret;
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for (int i = 0; i < n; i++){
            ret.push_back((digits[i] + carry)%10);
            carry = (digits[i] + carry)/10;
        }
        if (carry == 1) ret.push_back(carry);
        reverse(ret.begin(), ret.end());
    }
};