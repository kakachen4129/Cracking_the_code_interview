class Solution {
public:
    int calculate(string s) {
        vector<int> operand, op;
        string str = removeSpace(s);
        int i = 0;
        int n = str.size();
        while (i < n){
            if (isNumber(str[i])){
                int t = getNumber(str, i);
                operand.push_back(t);
            } else{
                if (str[i] == '+' || str[i] == '-'){
                    op.push_back(str[i++]);
                } else{
                    int tmp = operand.size();
                    int val = operand[tmp-1];
                    char ch = str[i++];
                    operand[tmp-1] = calc(val, ch, getNumber(str, i));
                }
            }
        }
        if (operand.size() == 0)   return 0;
        int res = operand[0];
        for (int i = 1; i < operand.size(); i++)
            res = calc(res, op[i-1], operand[i]);
        return res;
    }
    string removeSpace(const string &s){
        string ret;
        int n = s.size();
        for (int i = 0; i < n; i++)
            if (s[i] != ' ')
                ret += s[i];
        return ret;
    }
    bool isNumber(char ch){
        return ch >= '0' && ch <= '9';
    }
    int getNumber(const string &s, int &pos){
        int n = s.size();
        int res = 0;
        while (pos < n && isNumber(s[pos]))
            res = res * 10 + s[pos++] - '0';
        return res;
    }
    int calc(int a, char op, int b){
        switch (op){
            case '+' : return a + b;
            case '-' : return a - b;
            case '*' : return a * b;
            case '/' : return a / b;
            default  : return 0;
        }
    }
};