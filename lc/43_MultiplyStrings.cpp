class Solution {
public:
string add(const string &s1, const string &s2){
    string ret;
    int carry = 0;
    int pos = 0;
    while (pos < s1.size() || pos < s2.size()){
        int sum = carry;
        if (pos < s1.size())
            sum += s1[pos] - '0';
        if (pos < s2.size())
            sum += s2[pos] - '0';
        carry = sum / 10;
        ret.push_back(sum % 10 + '0');
        pos++;
    }
    if (carry != 0)
        ret.push_back(carry + '0');
    return ret;
}

string multi(const string &s, const char ch){
    int carry = 0;
    string ret;
    for (int i = 0; i < s.size(); i++){
        int tmp = (ch - '0') * (s[i] - '0') + carry;
        carry = tmp / 10;
        ret.push_back(tmp % 10 + '0');
    }
    if (carry != 0)
        ret.push_back(carry + '0');
    return ret;
}

string multiply(string num1, string num2) {
    int l1 = num1.size();
    int l2 = num2.size();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string ret;
    for (int i = 0; i < l1; i++){
        string tmp;
        for (int j = 0; j < i; j++)
            tmp += "0";
        tmp += multi(num2, num1[i]);
        ret = add(ret, tmp);
    }
    reverse(ret.begin(), ret.end());
    if (ret.size() != 0 && ret[0] == '0')
        return "0";
    return ret;        
}
};
